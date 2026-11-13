#include "common.h"

/* localdecomp:start func_L39_006979B0 */
typedef struct S_006979B0_list S_006979B0_list;
typedef struct {
    char pad[0x88];
    void (*f88)(S_006979B0_list *, s32);
    s32 (*f8C)(S_006979B0_list *);
} S_006979B0_vt;
struct S_006979B0_list {
    char pad[0x60];
    S_006979B0_vt *f60;
};
typedef struct {
    char pad[0x114];
    S_006979B0_list *f114;
    char pad2[0x290 - 0x118];
    s32 f290;
    char pad3[0x2B0 - 0x294];
    s32 f2B0;
    char pad4[0x3B4 - 0x2B4];
    s32 f3B4;
} S_006979B0;

extern void func_L39_00688340(s32, s32, s32);
void func_L39_0068B2F8(s32, s32, s32);

s32 func_L39_006979B0(S_006979B0 *p, s32 event)
{
    s32 t;
    if (event == 3 || event == 4) {
        t = p->f290;
        if (t == 1) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8((s32)p, p->f3B4, 0);
            return 1;
        }
        func_L39_00688340(3, 0, 0);
        t = p->f290;
        p->f3B4 = t;
        func_L39_0068B2F8((s32)p, 1, 0);
        return 1;
    }
    if (event == 2) {
        if (p->f290 == 1 && p->f114->f60->f8C(p->f114) == p->f2B0 - 1) {
            p->f114->f60->f88(p->f114, 0);
            return 1;
        }
        if (p->f290 == 16) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8((s32)p, 9, 0);
            return 1;
        }
    } else if (event == 1) {
        if (p->f290 == 1 && p->f114->f60->f8C(p->f114) == 0) {
            p->f114->f60->f88(p->f114, p->f2B0 - 1);
            return 1;
        }
        if (p->f290 == 9) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8((s32)p, 16, 0);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006979B0 */

/* localdecomp:start func_L39_00697B28 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");

typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_00697B28_inner;

typedef struct {
    char pad[0x38];
    S_00697B28_inner *f38;
} S_00697B28_outer;

typedef struct {
    char pad[0x288];
    s32 f288;
} S_00697B28_slot;

extern S_00697B28_outer *D_L39_0024D760;
extern S_00697B28_slot *D_L39_00247914;
extern S_00697B28_slot *D_001DC204_sda;

s32 func_L39_00697B28(void)
{
    S_00697B28_inner *inner = D_L39_0024D760->f38;

    if (inner->f0 == -1) {
        D_L39_00247914->f288 = 8;
        return 1;
    }
    if (inner->f34 == 0) {
        D_001DC204_sda->f288 = 6;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00697B28 */

INCLUDE_ASM("asm/levels", func_L39_00697B80);
