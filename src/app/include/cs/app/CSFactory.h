#pragma once

#include <memory>
#include <unordered_map>
#include <string>

#include <cstdlib>
#ifdef _GCC
#include <cxxabi.h>
#endif

namespace cs
{
    namespace app
    {
#ifdef _GCC
        std::string demangle(const char* name)
        {
            int status = -4; // some arbitrary value to eliminate the compiler warning
            std::unique_ptr<char, void (*)(void*)> res{
                abi::__cxa_demangle(name, NULL, NULL, &status), std::free
            };

            return (status == 0) ? res.get() : name;
        }
#endif

        template<typename BaseClass, class... Args>
        class CSFactory
        {
            friend BaseClass;
        public:
            template<class ... T>
            static std::unique_ptr<BaseClass> Create(const std::string& s, T&&... args)
            {
                return data().at(s)(std::forward<T>(args)...);
            }

        public:
            template <class T>
            struct Registrar : BaseClass {
                friend T;
                static bool registerT()
                {
#ifdef _GCC
                    const auto name = demangle(typeid(T).name());
#else
                    const auto name = T::name;
#endif
                    Facotry::data()[name] = [](Args... args) -> std::unique_ptr<BaseClass> {
                        return std::make_unique<T>(std::forword<Args>(args)...);
                    }
                    return true;
                }
                static bool registered;

            private:
                Registrar() : Base(Key{}) { (void)registered; }
            };

        private:
            class Key {
                Key() {};
                template <class T> friend struct Registrar;
            };

            using FuncType = std::unique_ptr<BaseClass>(*) (Args...);
            CSFactory() = default;

            static auto& data()
            {
                static std::unordered_map<std::string, FuncType> s;
                return s;
            }
        };

        template<class BaseClass, class... Args>
        template<class T>
        bool CSFactory<BaseClass, Args...>::Registrar<T>::registered = CSFactory<BaseClass, Args...>::Registrar<T>::registerT();

    } // namespace app

} // namespace cs
