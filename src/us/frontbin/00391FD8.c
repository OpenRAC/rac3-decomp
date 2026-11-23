#include "common.h"

/* NTSC-U frontbin counterpart of func_00396838. */
typedef struct {
    u8 p0[0x18];
    void (*f18)(void *);
    u8 p1c[0x74];
} S_391FD8;

/* localdecomp:start func_U_00391FD8 */
extern S_391FD8 D_U_0032DB20[];
extern s32 D_U_001D9F40;
extern s32 D_001D9F3C_00391FD8;
extern s32 D_U_001D9C5C;
extern s32 D_U_001D9F14;
extern s32 D_U_001D9E80;
/* Retail addresses these two globals both absolutely and through $gp. */
extern s32 D_001D9E78_00391FD8;
extern s32 D_001D9E7C_00391FD8;
extern s32 D_U_001D9E78;
__asm__(".extern D_U_001D9E78, 4");
extern s32 D_U_001D9E7C;
__asm__(".extern D_U_001D9E7C, 4");
extern s32 D_U_001D5B94;
__asm__(".extern D_U_001D5B94, 4");

void func_U_00391FD8(void) {
    S_391FD8 *p;
    s32 i;
    if (D_U_001D9F40 || D_U_001D9C5C) {
        (&D_001D9F3C_00391FD8)[1] = 0;
        return;
    }
    D_U_001D9F14 = 0xFFFFF0;
    p = D_U_0032DB20;
    for (i = 12; i >= 0; i--) {
        if (p->f18) p->f18(p);
        p++;
    }
    if (D_001D9E78_00391FD8 || D_001D9E7C_00391FD8) {
        if (D_U_001D5B94 == 0) {
            if (D_001D9E78_00391FD8) {
                D_U_001D9E7C += 0x10;
                if (D_U_001D9E7C > 0x80) D_U_001D9E7C = 0x80;
            } else {
                D_U_001D9E7C -= 0x10;
                if (D_U_001D9E7C < 0) D_001D9E7C_00391FD8 = 0;
            }
            if (D_001D9E78_00391FD8) D_001D9E78_00391FD8 = D_001D9E78_00391FD8 - 1;
            if (D_001D9E78_00391FD8 == 1000) D_U_001D9E78 = 0;
            return;
        }
    }
    D_U_001D9E80 = 100;
}
/* localdecomp:end func_U_00391FD8 */
