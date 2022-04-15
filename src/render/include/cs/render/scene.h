#pragma once

#include <cs/render/render_common.h>
#include <cs/render_fwd.h>

#include <memory>

namespace cs
{
    namespace render
    {
        class DECL_CS_RENDER Scene
        {
        private:
            /* data */
        public:
            Scene(/* args */);
            ~Scene();

        public:
            void Add(CSDisplayableObject* mesh);
            void Update();
            CSDisplayableObject* RootObject() const;

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };
    } // namespace render

} // namespace cs
