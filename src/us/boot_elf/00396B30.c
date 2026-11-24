#include "common.h"

/* NTSC-U boot counterpart of func_00396C18. */
typedef struct {
    u8 p0[0x18];
    void (*f18)(void *);
    u8 p1c[0x74];
} S_396B30;

/* localdecomp:start func_U_00396B30 */
extern S_396B30 D_U_00331B60[];
extern s32 D_U_001D9F40;
extern s32 D_001D9F3C_00396B30;
extern s32 D_U_001D9C5C;
extern s32 D_U_001D9F14;
extern s32 D_U_001D9E80;
/* Retail addresses these two globals both absolutely and through $gp. */
extern s32 D_001D9E78_00396B30;
extern s32 D_001D9E7C_00396B30;
extern s32 D_U_001D9E78;
__asm__(".extern D_U_001D9E78, 4");
extern s32 D_U_001D9E7C;
__asm__(".extern D_U_001D9E7C, 4");
extern s32 D_U_001D5B94;
__asm__(".extern D_U_001D5B94, 4");

void func_U_00396B30(void) {
    S_396B30 *p;
    s32 i;
    if (D_U_001D9F40 || D_U_001D9C5C) {
        (&D_001D9F3C_00396B30)[1] = 0;
        return;
    }
    D_U_001D9F14 = 0xFFFFF0;
    p = D_U_00331B60;
    for (i = 12; i >= 0; i--) {
        if (p->f18) p->f18(p);
        p++;
    }
    if (D_001D9E78_00396B30 || D_001D9E7C_00396B30) {
        if (D_U_001D5B94 == 0) {
            if (D_001D9E78_00396B30) {
                D_U_001D9E7C += 0x10;
                if (D_U_001D9E7C > 0x80) D_U_001D9E7C = 0x80;
            } else {
                D_U_001D9E7C -= 0x10;
                if (D_U_001D9E7C < 0) D_001D9E7C_00396B30 = 0;
            }
            if (D_001D9E78_00396B30) D_001D9E78_00396B30 = D_001D9E78_00396B30 - 1;
            if (D_001D9E78_00396B30 == 1000) D_U_001D9E78 = 0;
            return;
        }
    }
    D_U_001D9E80 = 100;
}
/* localdecomp:end func_U_00396B30 */
