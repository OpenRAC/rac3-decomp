#include "common.h"

/* localdecomp:start func_L11_003FCE88 */
typedef struct { u8 pad0[0x44]; s16 count; u8 pad46[0x1A0 - 0x46]; u8 *mobys[1]; } L_3FCE88;
extern L_3FCE88 D_L11_001E5AC0;
extern u8 *D_L11_00238130[];
extern s32 D_001D545C;
__asm__(".extern D_L11_001D6A90, 4");
extern f32 D_L11_001D6A90;
extern f32 D_L11_001D6A94;
extern f32 D_L11_001D6A98;
extern void func_L01_00423AB8(void);
extern void func_003A58C0(void *, s32);
extern void func_003A7AF8(void *);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00424168(void *);
extern void func_L11_003FCBD0(void);

void func_L11_003FCE88(void)
{
    s32 i;
    u8 *m;
    s16 id;
    s32 j;

    func_L01_00423AB8();
    for (i = 0; i < D_L11_001E5AC0.count; i++) {
        m = D_L11_001E5AC0.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) {
            *(u16 *)(m + 0x34) |= 0x800;
        }
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L11_00238130[j] != 0; j++) {
                if (D_L11_00238130[j][0x63] != 0) {
                    D_L11_00238130[j][0x63] = 1;
                }
            }
            func_003A58C0(m, 0);
            func_L01_004048D0(func_003A7AF8, m);
        }
        if (m != 0) {
            id = *(s16 *)(m + 0xAA);
            if (id == 0xFA0) {
                if (*(u8 **)(m + 0x68) != 0) {
                    func_L01_00451DB8(m, *(u8 **)(m + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.07330383f);
                }
            } else if (id == 0x1DEE || id == 0x19BC) {
                func_L01_00451DB8(m, &D_L11_001D6A90, 0x80505080, 0x80404038, 0.038397245f);
            } else if (id == 0x1977) {
                func_L01_00451DB8(m, &D_L11_001D6A94, 0x8080AAAA, 0x80464646, 0.045378566f);
            } else if (id == 0x1766) {
                func_L01_00451DB8(m, &D_L11_001D6A98, 0x80AAAAFF, 0x80646496, 0.13264504f);
            } else if (id == 0x195B || id == 0x1B58 || id == 0x195C || id == 0x175A) {
                func_L01_00404808(func_L01_00424168, m);
            }
        }
    }
    if (D_001D545C == 11) {
        func_L01_00404808(func_L11_003FCBD0, 0);
    }
}
/* localdecomp:end func_L11_003FCE88 */
