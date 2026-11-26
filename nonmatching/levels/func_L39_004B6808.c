/* PAL draft (k6 a5, 2026-11-26): phkmalloc's ifree() with free_pages() and free_bytes() inlined, as
 * Sony's DNAS allocator has it (seven protected blocks; Sony's texts, no madvise, no return of
 * memory to the system, page and byte counters). 395 differences with the file's line; 243 with
 * -fno-strict-aliasing added, which retail's reloads of the delayed-free pointer after the
 * void * stores suggest (every other C function of L39_004B5960.c still matches with it except
 * func_L39_004B5BE8, 1 word). Left: the `if (!malloc_started)` delay slot (beql/bnez, as in
 * func_L39_004B6108), and `if (pt) ifree(pt)` is a sibling call in retail and a jal here. */
#include "common.h"
/* localdecomp:start func_L39_004B6808 */
/* ifree() of phkmalloc (FreeBSD's malloc) with free_pages() and free_bytes() inlined, as Sony's
 * DNAS allocator has it: Sony's texts, no madvise and no return of memory to the system, and it
 * counts the pages and bytes in use */
extern s32 D_L39_004646F0;
/* phkmalloc's struct pgfree, the free list's page runs (S_004B59D8 with its own types) */
typedef struct Pgfree_004B6808 {
    struct Pgfree_004B6808 *next;
    struct Pgfree_004B6808 *prev;
    void *page;
    void *end;
    u32 size;
} Pgfree_004B6808;
extern Pgfree_004B6808 *D_L39_003E43E8_004B6808;   /* px */
extern Pgfree_004B6808 *D_L39_003E43B8_004B6808;   /* free_list.next */

void func_L39_004B6808(S_004B59D8 *ptr) {
    P_004B5BE8 *info;
    u32 index;
    u32 i;
    u32 l;
    void *tail;
    Pgfree_004B6808 *pf;
    Pgfree_004B6808 *pt;
    P_004B5BE8 **mp;
    void *vp;

    if (!ptr) {
        return;
    }
    DNAS_BEGIN(func_L39_004B6808, 0, func_L39_004BD350);
    if (!D_L39_004646F0) {
        func_L39_004B5958(DNAS_STRING("malloc() has never been called."));
        return;
    }
    if (D_L39_003E43D0) {
        return;
    }
    index = (((u32)ptr + D_L39_003E43A0[0]) >> D_L39_003E4390[0]) - D_L39_003E43A4[0];
    if (index < D_L39_003E4390[0]) {
        func_L39_004B5958(DNAS_STRING("junk pointer, too low to make sense."));
        return;
    }
    if (index > D_L39_003E43A8[0]) {
        func_L39_004B5958(DNAS_STRING("junk pointer, too high to make sense."));
        return;
    }
    DNAS_END_ONCE(func_L39_004B6808, 0);
    info = (P_004B5BE8 *)D_L39_003E43AC[index];
    if ((u32)info < 4) {
        /* free_pages() */
        pt = 0;
        if ((u32)info == 1) {
            DNAS_BEGIN(func_L39_004B6808, 1, func_L39_004BD350);
            func_L39_004B5958(DNAS_STRING("page is already free."));
            DNAS_END_ONCE(func_L39_004B6808, 1);
            return;
        }
        if ((u32)info != 2) {
            DNAS_BEGIN(func_L39_004B6808, 2, func_L39_004BD350);
            func_L39_004B5958(DNAS_STRING("pointer to wrong page."));
            DNAS_END_ONCE(func_L39_004B6808, 2);
            return;
        }
        if (((u32)ptr + D_L39_003E43A0[0]) & D_L39_003E4394) {
            DNAS_BEGIN(func_L39_004B6808, 3, func_L39_004BD350);
            func_L39_004B5958(DNAS_STRING("modified (page-) pointer."));
            DNAS_END_ONCE(func_L39_004B6808, 3);
            return;
        }
        D_L39_003E43AC[index] = 1;
        for (i = 1; D_L39_003E43AC[index + i] == 3; i++) {
            D_L39_003E43AC[index + i] = 1;
        }
        D_L39_003E4400 -= i;
        D_L39_003E43FC -= i * D_L39_003E438C;
        l = i << D_L39_003E4390[0];
        if (D_L39_003E43E4) {
            func_0011D534(ptr, 0xD0, l);
        }
        tail = (u8 *)ptr + l;
        if (!D_L39_003E43E8_004B6808) {
            D_L39_003E43E8_004B6808 = func_L39_004B5F68(sizeof *pt);
        }
        D_L39_003E43E8_004B6808->page = ptr;
        D_L39_003E43E8_004B6808->end = tail;
        D_L39_003E43E8_004B6808->size = l;
        if (!D_L39_003E43B8_004B6808) {
            D_L39_003E43E8_004B6808->next = D_L39_003E43B8_004B6808;
            D_L39_003E43E8_004B6808->prev = (Pgfree_004B6808 *)&D_L39_003E43B8_004B6808;
            D_L39_003E43B8_004B6808 = D_L39_003E43E8_004B6808;
            pf = D_L39_003E43E8_004B6808;
            D_L39_003E43E8_004B6808 = 0;
        } else {
            tail = (u8 *)ptr + l;
            for (pf = D_L39_003E43B8_004B6808; pf->end < (void *)ptr && pf->next; pf = pf->next)
                ;
            if (pf->page > tail) {
                D_L39_003E43E8_004B6808->next = pf;
                D_L39_003E43E8_004B6808->prev = pf->prev;
                pf->prev = D_L39_003E43E8_004B6808;
                D_L39_003E43E8_004B6808->prev->next = D_L39_003E43E8_004B6808;
                pf = D_L39_003E43E8_004B6808;
                D_L39_003E43E8_004B6808 = 0;
            } else if (pf->end == (void *)ptr) {
                pf->end = (u8 *)pf->end + l;
                pf->size += l;
                if (pf->next && pf->end == pf->next->page) {
                    pt = pf->next;
                    pf->end = pt->end;
                    pf->size += pt->size;
                    pf->next = pt->next;
                    if (pf->next) {
                        pf->next->prev = pf;
                    }
                }
            } else if (pf->page == tail) {
                pf->size += l;
                pf->page = ptr;
            } else if (!pf->next) {
                D_L39_003E43E8_004B6808->next = 0;
                D_L39_003E43E8_004B6808->prev = pf;
                pf->next = D_L39_003E43E8_004B6808;
                pf = D_L39_003E43E8_004B6808;
                D_L39_003E43E8_004B6808 = 0;
            } else {
                DNAS_BEGIN(func_L39_004B6808, 4, func_L39_004BD350);
                func_L39_004B5950(DNAS_STRING("freelist is destroyed."));
                DNAS_END_ONCE(func_L39_004B6808, 4);
            }
        }
        if (pt) {
            func_L39_004B6808((S_004B59D8 *)pt);
        }
    } else {
        /* free_bytes() */
        i = (((u32)ptr + D_L39_003E43A0[0]) & D_L39_003E4394) >> info->shift;
        if (((u32)ptr + D_L39_003E43A0[0]) & (info->size - 1)) {
            DNAS_BEGIN(func_L39_004B6808, 5, func_L39_004BD350);
            func_L39_004B5958(DNAS_STRING("modified (page-) pointer."));
            DNAS_END_ONCE(func_L39_004B6808, 5);
            return;
        }
        if (info->bitmap[i / 32] & (1 << (i % 32))) {
            DNAS_BEGIN(func_L39_004B6808, 6, func_L39_004BD350);
            func_L39_004B5958(DNAS_STRING("page is already free."));
            DNAS_END_ONCE(func_L39_004B6808, 6);
            return;
        }
        if (D_L39_003E43E4) {
            func_0011D534(ptr, 0xD0, info->size);
        }
        info->bitmap[i / 32] |= 1 << (i % 32);
        info->free++;
        D_L39_003E43FC -= info->size;
        mp = (P_004B5BE8 **)D_L39_003E43AC + info->shift;
        if (info->free == 1) {
            while (*mp && (*mp)->next && (*mp)->next->base < info->base) {
                mp = &(*mp)->next;
            }
            info->next = *mp;
            *mp = info;
            return;
        }
        if (info->free != info->total) {
            return;
        }
        while (*mp != info) {
            mp = &((*mp)->next);
        }
        *mp = info->next;
        D_L39_003E43AC[index] = 2;
        vp = (void *)info->base;
        if (vp != (void *)info) {
            func_L39_004B6808((S_004B59D8 *)info);
        }
        D_L39_003E43FC += D_L39_003E438C;
        func_L39_004B6808((S_004B59D8 *)vp);
    }
}
/* localdecomp:end func_L39_004B6808 */
