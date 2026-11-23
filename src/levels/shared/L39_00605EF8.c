#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00605EF8);

/* localdecomp:start func_L39_006068A0 */
typedef struct { s32 w0; s32 w4; s32 w8; u8 pad[0x10]; } E_006068A0;
typedef struct { u8 pad[0x2544]; s32 idx; } P_006068A0;
extern P_006068A0 *func_L39_0061BF38(s32);
extern E_006068A0 D_L39_004840A0[];
extern f32 D_L39_0025D6C0[];
extern void func_L39_005872D8(void);
extern s32 *func_L39_006010E0(void *);
extern f32 *func_L39_006010D8(void *);
extern void func_L39_006015C0(void *);
extern void func_L01_00430110(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003AB890(void *);
extern void func_003AAF00(void *, s32);
extern void func_L39_00602258(s32, s32, u32 *, u32 *, u32 *);
extern s32 D_001D9FA0_sda;
__asm__(".extern D_001D9FA0_sda, 4");
extern s32 D_001D9FA4_sda;
__asm__(".extern D_001D9FA4_sda, 4");
extern s32 D_001D9FA8_sda;
__asm__(".extern D_001D9FA8_sda, 4");
extern s32 D_001D9FAC_sda;
__asm__(".extern D_001D9FAC_sda, 4");
extern s32 D_001D9FB0_sda;
__asm__(".extern D_001D9FB0_sda, 4");
extern u32 D_001D9FB4_sda;
__asm__(".extern D_001D9FB4_sda, 4");
typedef struct { u8 pad[0x18]; s32 id; } R_006068A0;
extern R_006068A0 **D_L39_0024BD48[] __attribute__((section(".sdata")));

void func_L39_006068A0(void *self, s32 pl) {
    u8 *obj = self;
    f32 saved;
    u8 *t;
    s32 i;
    u32 mask;
    u8 *label;
    u8 *c;
    u8 *e;
    u8 *d;
    u8 *p;
    s32 j;
    u32 c0, c1;
    s32 k;
    s32 idx;

    idx = func_L39_0061BF38(pl)->idx;
    if (D_L39_004840A0[idx].w0 == 0) {
        saved = D_L39_0025D6C0[44];
        if (saved != 0.62f) {
            D_L39_0025D6C0[44] = 0.62f;
            func_L39_005872D8();
        }
        t = obj + 0x628;
        c = obj + 0x5C8;
        d = obj + 0x5F8;
        e = obj + 0xA90;
        *func_L39_006010E0(obj + 0x244) = D_001D9FA0_sda;
        *func_L39_006010E0(obj + 0x4D8) = D_001D9FA4_sda;
        *func_L39_006010E0(obj + 0x280) = D_001D9FA8_sda;
        *func_L39_006010E0(obj + 0x514) = D_001D9FAC_sda;
        *func_L39_006010E0(obj + 0x49C) = D_001D9FB0_sda;
        *func_L39_006010E0(obj + 0x550) = D_001D9FA0_sda;
        *func_L39_006010E0(obj + 0x58C) = D_001D9FAC_sda;
        func_L01_00430110(1);
        func_003A9440(0x47, 0x513F1);
        func_L39_006015C0(obj + 0x244);
        func_L39_006015C0(obj + 0x4D8);
        func_L39_006015C0(obj + 0x280);
        func_L39_006015C0(obj + 0x514);
        func_L39_006015C0(obj + 0x49C);
        func_L39_006015C0(obj + 0x550);
        func_L39_006015C0(obj + 0x58C);
        {
            f32 *f;
            f = func_L39_006010D8(obj + 0x244); *f = -*f;
            f = func_L39_006010D8(obj + 0x4D8); *f = -*f;
            f = func_L39_006010D8(obj + 0x280); *f = -*f;
            f = func_L39_006010D8(obj + 0x514); *f = -*f;
            f = func_L39_006010D8(obj + 0x49C); *f = -*f;
        }
        func_L39_006015C0(obj + 0x244);
        func_L39_006015C0(obj + 0x4D8);
        func_L39_006015C0(obj + 0x280);
        func_L39_006015C0(obj + 0x514);
        func_L39_006015C0(obj + 0x49C);
        {
            f32 *f;
            f = func_L39_006010D8(obj + 0x244); *f = -*f;
            f = func_L39_006010D8(obj + 0x4D8); *f = -*f;
            f = func_L39_006010D8(obj + 0x280); *f = -*f;
            f = func_L39_006010D8(obj + 0x514); *f = -*f;
            f = func_L39_006010D8(obj + 0x49C); *f = -*f;
        }
        func_L39_006015C0(t);
        label = obj + 0x628;
        p = obj + 0x664;
        mask = 0xFFFFFF;
        for (i = 0; i < 8; i++) {
            s32 *r;
            if (D_L39_0024BD48[pl] != 0 && (*D_L39_0024BD48[pl])[i].id > 0) {
                func_L39_00602258(pl, (*D_L39_0024BD48[pl])[i].id, &c0, &c1, &D_001D9FB4_sda);
            }
            r = func_L39_006010E0(p);
            p += 0x30;
            *r = (*r & 0xFF000000) | (D_001D9FB4_sda & mask);
        }
        for (j = 0; j < 8; j++) {
        }
        {
            s32 *r = func_L39_006010E0(c);
            *r = (*r & 0xFF000000) | 0x6EC8FF;
        }
        {
            s32 *r = func_L39_006010E0(d);
            *r = (*r & 0xFF000000) | 0x6EC8FF;
        }
        for (k = 0; k < 8; k++) {
            void (*fn)(void *);
            fn = (void (*)(void *))(*(s32 **)(obj + 0x688 + k * 0x30))[2];
            t = obj + 0x664 + k * 0x30;
            fn(t);
        }
        func_003AB890(c);
        func_003AB890(d);
        *func_L39_006010E0(label) = 0x706EC8FF;
        if (e[0x28] == 0) {
            func_003AAF00(label, 0);
        }
        if (saved != 0.62f) {
            D_L39_0025D6C0[44] = saved;
            func_L39_005872D8();
        }
    }
    func_L01_00430110(0);
}
/* localdecomp:end func_L39_006068A0 */
