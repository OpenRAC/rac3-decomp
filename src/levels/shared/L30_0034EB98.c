#include "common.h"

/* localdecomp:start func_L30_0034EB98 */
typedef struct { u8 pad[0x18]; s32 x18; } V_34EB98;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; u8 x20; u8 pad21[0x68 - 0x21]; V_34EB98 *x68; } O_34EB98;
__asm__(".extern D_L30_001DD61C, 4");
__asm__(".extern D_L30_001DD634, 4");
__asm__(".extern D_L30_001DD638, 4");
__asm__(".extern D_L30_001DD64C, 4");
__asm__(".extern D_L30_001DD650, 4");
__asm__(".extern D_L30_001DD670, 4");
__asm__(".extern D_L30_001DD674, 4");
__asm__(".extern D_L30_001DD680, 4");
__asm__(".extern D_L30_001DD684, 4");
__asm__(".extern D_L30_001DD694, 4");
__asm__(".extern D_L30_001DD698, 4");
__asm__(".extern D_L30_001DD6A4, 4");
__asm__(".extern D_L30_001DD6A8, 4");
__asm__(".extern D_L30_001DD6CC, 4");
__asm__(".extern D_L30_001DD6D0, 4");
__asm__(".extern D_L30_001DD6DC, 4");
__asm__(".extern D_L30_001DD6E0, 4");
__asm__(".extern D_L30_001DD708, 4");
__asm__(".extern D_L30_001DD70C, 4");
__asm__(".extern D_L30_001DD718, 4");
__asm__(".extern D_L30_001DD71C, 4");
__asm__(".extern D_L30_001DD600, 4");
__asm__(".extern D_L30_001DD60C, 4");
__asm__(".extern D_L30_001DD5F0, 4");
__asm__(".extern D_L30_001DD5F4, 4");
__asm__(".extern D_L30_001DD5EC, 4");
extern s32 D_L30_001DD61C;
extern s32 D_L30_001DD634;
extern s32 D_L30_001DD638;
extern f32 D_L30_001DD64C;
extern s32 D_L30_001DD650;
extern s32 D_L30_001DD670;
extern s32 D_L30_001DD674;
extern f32 D_L30_001DD680;
extern s32 D_L30_001DD684;
extern s32 D_L30_001DD694;
extern s32 D_L30_001DD698;
extern f32 D_L30_001DD6A4;
extern s32 D_L30_001DD6A8;
extern s32 D_L30_001DD6CC;
extern s32 D_L30_001DD6D0;
extern f32 D_L30_001DD6DC;
extern s32 D_L30_001DD6E0;
extern s32 D_L30_001DD708;
extern s32 D_L30_001DD70C;
extern f32 D_L30_001DD718;
extern s32 D_L30_001DD71C;
extern s32 D_L30_001DD600;
extern s32 D_L30_001DD60C;
extern s32 D_L30_001DD5F0;
extern f32 D_L30_001DD5F4;
extern s32 D_L30_001DD5EC;
extern s32 D_L30_001E1280[4] __attribute__((section(".sdata")));
extern s32 D_L30_001E1290[4] __attribute__((section(".sdata")));
extern u8 D_L30_001E12A0;
extern u8 D_L30_001E12C0;
extern u8 D_L30_001E12E0;
extern u8 D_L30_001E1300;
extern u8 D_L30_001E1320;
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L30_0034F5D8(u8 *, u8 *);
extern void func_L30_0034F998(u8 *, u8 *);
extern void func_L30_0034FC30(u8 *, u8 *);
extern void func_L30_0034FE30(u8 *, u8 *);
extern void func_L30_00350050(u8 *, u8 *);
extern void func_L30_0034EFB8(O_34EB98 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L03_0034B248(void *, void *);
extern void func_L30_0034C8A8(void *, void *);
extern s32 func_L01_004561B8(void *);
extern void func_L30_003B3200(void *, s32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(u8 *p);
extern void func_L30_0034CB68(u8 *, void *, s32, s32, s32, s32, f32, f32);

void func_L30_0034EB98(O_34EB98 *o) {
    V_34EB98 *v = o->x68;
    s32 i;
    s32 t;

    if (D_L30_001DD61C == 0) {
        D_L30_001DD61C = 1;
        func_L03_0034B218(&D_L30_001E12A0, D_L30_001DD634, D_L30_001DD638, D_L30_001DD64C, D_L30_001DD650, (void *)func_L30_0034F5D8);
        func_L03_0034B218(&D_L30_001E12C0, D_L30_001DD670, D_L30_001DD674, D_L30_001DD680, D_L30_001DD684, (void *)func_L30_0034F998);
        func_L03_0034B218(&D_L30_001E12E0, D_L30_001DD694, D_L30_001DD698, D_L30_001DD6A4, D_L30_001DD6A8, (void *)func_L30_0034FC30);
        func_L03_0034B218(&D_L30_001E1300, D_L30_001DD6CC, D_L30_001DD6D0, D_L30_001DD6DC, D_L30_001DD6E0, (void *)func_L30_0034FE30);
        func_L03_0034B218(&D_L30_001E1320, D_L30_001DD708, D_L30_001DD70C, D_L30_001DD718, D_L30_001DD71C, (void *)func_L30_00350050);
        for (i = 0; i < 4; i++) {
            D_L30_001E1280[i] = 0;
            D_L30_001E1290[i] = 0;
        }
    }
    switch (o->x20) {
    case 0:
        func_L30_0034EFB8(o);
        if (func_0038CAD0(&v->x18) != 0) {
            func_L01_004450F0(o, 1, -1);
        }
        func_L03_0034B248(&D_L30_001E12C0, o);
        func_L30_0034C8A8(&D_L30_001E1320, o);
        break;
    case 1:
        if (func_L01_004561B8(o) != 0) {
            func_L30_003B3200(o->x10, D_L30_001DD6A8, 5.0f);
            t = D_L30_001DD600 + D_L30_001DD60C;
            v->x18 = t;
            func_003A52A0(1, 0, o);
        }
        if (func_0038CAD0(&v->x18) != 0) {
            func_003C2880((u8 *)o);
        } else {
            t = D_L30_001DD600 + D_L30_001DD60C - v->x18;
            if (t < D_L30_001DD5F0) {
                func_L30_0034CB68((u8 *)o, v, 0, -1, 0, 0, (f32)D_L30_001DD5EC, (f32)t / (f32)D_L30_001DD5F0 * D_L30_001DD5F4);
            }
        }
        break;
    }
}
/* localdecomp:end func_L30_0034EB98 */
