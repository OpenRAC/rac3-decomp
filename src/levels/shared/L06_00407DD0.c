#include "common.h"

/* localdecomp:start func_L06_00407DD0 */
typedef struct {
    u8 pad0[0x44];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[1];
} L_00407DD0;

extern L_00407DD0 D_L06_001E5A40;
extern u8 *D_L06_002380B0[];
extern f32 D_L06_001D6A90;
__asm__(".extern D_L06_001D6A90, 4");
extern f32 D_L06_001D6A94;
__asm__(".extern D_L06_001D6A94, 16");
extern f32 D_L06_001D6A98;
__asm__(".extern D_L06_001D6A98, 16");
extern void func_L01_00423AB8(void);
extern void func_003A58C0(void *, s32);
extern void func_003A7AF8(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00424168(void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);

void func_L06_00407DD0(void) {
    s32 i;
    u8 *m;
    s16 id;
    s32 j;

    func_L01_00423AB8();
    for (i = 0; i < D_L06_001E5A40.count; i++) {
        m = D_L06_001E5A40.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) {
            *(u16 *)(m + 0x34) |= 0x800;
        }
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L06_002380B0[j] != 0; j++) {
                if (D_L06_002380B0[j][0x63] != 0) {
                    D_L06_002380B0[j][0x63] = 1;
                }
            }
            func_003A58C0(m, 0);
            func_L01_00404A10(func_003A7AF8, m);
        }
        if (m != 0) {
            id = *(s16 *)(m + 0xAA);
            if (id == 0xFA0) {
                if (*(u8 **)(m + 0x68) != 0) {
                    func_L01_00451DB8(m, *(u8 **)(m + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.073303834f);
                }
            } else if (id == 0x1DEE || id == 0x19BC) {
                func_L01_00451DB8(m, &D_L06_001D6A90, 0x80505080, 0x80404038, 0.038397245f);
            } else if (id == 0x1977) {
                func_L01_00451DB8(m, &D_L06_001D6A94, 0x8080AAAA, 0x80464646, 0.045378566f);
            } else if (id == 0x1766) {
                func_L01_00451DB8(m, &D_L06_001D6A98, 0x80AAAAFF, 0x80646496, 0.13264504f);
            } else if (id == 0x195B || id == 0x1B58 || id == 0x195C || id == 0x175A) {
                func_L01_00404808(func_L01_00424168, m);
            }
        }
    }
}
/* localdecomp:end func_L06_00407DD0 */

LINKER_REMNANT("asm/levels", func_L06_004281F0);
