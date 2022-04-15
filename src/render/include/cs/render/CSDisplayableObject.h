#pragma once

#include <cs/render/render_common.h>

#include <cs/core_fwd.h>
#include <memory>

namespace cs
{
    namespace render
    {
        class CSMaterial;

        class DECL_CS_RENDER CSDisplayableObject
        {
        private:
            /* data */
        public:
            CSDisplayableObject() : _visible(true), _cachedMesh(nullptr) {}
            ~CSDisplayableObject() {}

        public:
            void Show() { _visible = true; }
            void Hide() { _visible = false; }
            bool GetVisible() const { return _visible; }

            std::shared_ptr<cs::core::CSBufferObject> GetBuffer() const { return _cachedMesh; }
            virtual void Test() {}

        protected:
            void setBuffer(std::shared_ptr<cs::core::CSBufferObject> _);

        private:
            bool _visible;
            std::shared_ptr<cs::core::CSBufferObject> _cachedMesh;
        };

        class DECL_CS_RENDER CSDisplayableObject2d : public CSDisplayableObject
        {
        public:
            CSDisplayableObject2d(const cs::core::CSObject&, const CSMaterial&);

        };

    } // namespace render

} // namespace cs
