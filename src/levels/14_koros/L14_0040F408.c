#include "common.h"

/* localdecomp:start func_L14_0040F408 */
#include "vu0.h"

typedef struct {
    u8 p0[0x30];
    s32 w30;
    s32 w34;
    u8 p38[0xC];
    s16 count;
    u8 p46[0x15A];
    u8 *mobys[5];
} S_0040F408;

extern S_0040F408 D_L14_001E6480;
extern u8 *D_L14_00239530[];
extern f32 D_L14_001D6A90;
__asm__(".extern D_L14_001D6A90, 4");
extern f32 D_L14_001D6A94;
extern f32 D_L14_001D6A98;
extern s32 D_L14_001D6B88[] __attribute__((section(".sdata")));
extern f32 D_L14_001D6B98[] __attribute__((section(".sdata")));
extern f32 D_L14_001D6BA8[] __attribute__((section(".sdata")));
__asm__(".extern D_L14_001D6B88, 8");
__asm__(".extern D_L14_001D6B98, 8");
__asm__(".extern D_L14_001D6BA8, 8");
extern f32 D_L14_001DF058;
extern s32 D_001D545C;

extern void func_L01_00423AB8(void);
extern void func_003A58C0(void *, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_L01_00404808(void *, void *);
extern u8 *func_L14_0040E5C8(s32);
extern void func_L14_0040EA08(void);
extern void func_L14_0040EF88(u8 *, s32, s32, s32, f32, f32);
extern void func_L14_0040F1B8(u8 *, s32);
extern void func_003A7AF8(void *);
extern void func_L01_00424168(void *);
extern void func_L14_0040E918(void *);
extern void func_L14_0040EA78(void *);

/* from the NTSC-U draft of func_L14_0040C510 */
void func_L14_0040F408(void) {
    s32 i;
    u8 *m;
    s32 j;
    s16 t;
    u8 *obj;
    u8 *e;
    s32 k;
    vu0_v4 v;

    func_L01_00423AB8();
    for (i = 0; i < D_L14_001E6480.count; i++) {
        m = D_L14_001E6480.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) *(u16 *)(m + 0x34) |= 0x800;
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L14_00239530[j] != 0; j++) {
                if (D_L14_00239530[j][0x63] != 0) D_L14_00239530[j][0x63] = 1;
            }
            func_003A58C0(m, 0);
            func_L01_00404A10(func_003A7AF8, m);
        }
        if (m == 0) continue;
        t = *(s16 *)(m + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(m + 0x68) != 0) {
                func_L01_00451DB8(m, *(u8 **)(m + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.0733038336f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_00451DB8(m, &D_L14_001D6A90, 0x80505080, 0x80404038, 0.0383972451f);
        } else if (t == 0x1977) {
            func_L01_00451DB8(m, &D_L14_001D6A94, 0x8080AAAA, 0x80464646, 0.0453785658f);
        } else if (t == 0x1766) {
            func_L01_00451DB8(m, &D_L14_001D6A98, 0x80AAAAFF, 0x80646496, 0.132645041f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00404808(func_L01_00424168, m);
        }
    }
    if (D_001D545C == 0xE) {
        if (D_L14_001E6480.w30 == 0 && D_L14_001E6480.w34 < 0x5F) {
            e = func_L14_0040E5C8(0x1C93);
            func_L01_00404808(func_L14_0040E918, e);
        }
        if (D_L14_001E6480.w30 == 1) {
            *(vu0_q *)&v = 0;
            v.y = 0.20902063f;
            v.z = 2.05327511f;
            v.w = 1.0f;
            func_L14_0040EA08();
            obj = D_L14_001E6480.mobys[4];
            if (obj != 0 && D_L14_001E6480.w34 >= 0x42F) {
                *(vu0_v4 *)(obj + 0xF0) = v;
                func_L01_00404808(func_L14_0040EA78, 0);
                if (D_L14_001E6480.w34 < 0x47F) {
                    for (j = 0; j < 4; j++) {
                        if (!(D_L14_001E6480.w34 < (D_L14_001D6B88[j] * 5 + 2) / 6)) {
                            func_L14_0040EF88(obj, D_L14_001D6B88[j], D_L14_001E6480.w34 & 1, j, D_L14_001D6B98[j], D_L14_001D6BA8[j]);
                        }
                    }
                }
                func_L14_0040F1B8(obj, (s32)((f32)(D_L14_001E6480.w34 - 0x42F) / 54.0f * 14.0f));
                k = D_L14_001E6480.w34 - 0x46D;
                if ((u32)k < 0x12) {
                    if (D_L14_001DF058 < 1365.0f) {
                        D_L14_001DF058 = (f32)k * 0.25f;
                    } else {
                        D_L14_001DF058 = 1.0f;
                    }
                } else {
                    D_L14_001DF058 = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_L14_0040F408 */
