#pragma once
#include "math/vector.h"

class CBaseHandle {};

template <class T, class I = int> class CUtlMemory {
    public:
        T& operator[](int i) {
            return m_pMemory[i];
        };

        T* m_pMemory;
        int m_nAllocationCount;
        int m_nGrowSize;
};

template <class T, class A = CUtlMemory<T>> class CUtlVector {
    public:
        typedef A CAllocator;

        T& operator[](int i) {
            return m_Memory[i];
        };

        CAllocator m_Memory;
        int m_Size;
        T* m_pElements;
};

#define END_OF_FREE_LIST -1
#define ENTRY_IN_USE -2
struct GlowObjectDefinition_t {
    CBaseHandle m_hEntity;
    Vector m_vGlowColor;
    float m_flGlowAlpha;
    bool m_bRenderWhenOccluded;
    bool m_bRenderWhenUnoccluded;
    int m_nSplitScreenSlot;
    int m_nNextFreeSlot;
};

class CGlowObjectManager {
    public:
        CUtlVector<GlowObjectDefinition_t> m_GlowObjectDefinitions;
        int m_nFirstFreeSlot;
};
