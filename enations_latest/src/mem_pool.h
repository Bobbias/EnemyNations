//
// Created by Bobbias on 025, 2023-05-25.
//

#ifndef ENATIONS_MEM_POOL_H
#define ENATIONS_MEM_POOL_H
#pragma once

////////////////////////////////////////////////////////////////////////
// memory pool shit

#include <algorithm>
#include "vdmplay.h"

#include "netcmd.h"

template<class Strategy>
class memory_pool {
private:
    Strategy strat;
public:
    memory_pool() {
        strat.init();
    }

    void* alloc() {
        return strat.allocate();
    }

    void free(void *p) {
        strat.deallocate(p);
    }
};

template<unsigned int S, unsigned int N>
class mempool_std_heap {
private:
    // states of the heap nodes
    enum class State : uint8_t {
        FREE = 1, TAKEN = 0
    };

    struct Entry {
        State state; // the state of the memory chunk
        void *p; // pointer to the memory chunk

        // comparsion operator, needed for heap book keeping
        bool operator<(const Entry &other) const { return state < other.state; }
    };

    typedef unsigned int size_type; // convenience
private:
    size_type available; // number of memory chunks available
    Entry a[N]; // book keeping
    uint8_t buf[S * N]; // the actual memory, here will the objects be stored
public:
    void init() {
        // number of available memory chunks is the size of the memory pool
        available = N;

        // all memory chunks are free, pointers are initialized
        for (size_type i = 0; i < N; ++i) {
            a[i].state = State::FREE;
            a[i].p = reinterpret_cast<void *>(&buf[S * i]);
        }

        // make heap of book keeping array
        std::make_heap(a, a + N);
    }

    void* allocate() {
        // allocation not possible if memory pool has no more space
        if (available <= 0 || available > N) throw std::bad_alloc();

        // the first memory chunk is always on index 0
        Entry e = a[0];

        // remove first entry from heap
        std::pop_heap(a, a + N);

        // one memory chunk allocated, no more available
        --available;

        // mark the removed chunk
        a[available].state = State::TAKEN;
        a[available].p = NULL;

        // return pointer to the allocated memory
        return e.p;
    }

    void deallocate(void *ptr) {
        // invalid pointers are ignored
        if (!ptr || available >= N) return;

        // mark freed memory as such
        a[available].state = State::FREE;
        a[available].p = ptr;

        // freed memory chunk, one more available
        ++available;

        // heap book keeping
        std::push_heap(a, a + N);
    }
};

const int SMALL_POOL_SIZE = (48 + 3) & ~3;
// FIXME: This is supposed to be sizeof(CMsgBldgStat), but that class is not visible here for some reason.

typedef memory_pool<mempool_std_heap<VP_MAXSENDDATA, 10>> mempool_large;
typedef memory_pool<mempool_std_heap<SMALL_POOL_SIZE, 100>> mempool_small;

#endif //ENATIONS_MEM_POOL_H
