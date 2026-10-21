#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A56A0();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C6718);

typedef int Q_3C0E10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C0E10;
typedef struct { u8 p0[0x10]; V_3C0E10 pos; } O_3C0E10;
typedef struct { u8 p0[0x46]; u8 b46; } P_3C0E10;
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; u8 p18[0xC]; P_3C0E10 *f24; } E_3C0E10;
extern E_3C0E10 *D_0022B6C0[];
extern s32 func_003D50B8(void *, s32, void *, s32, f32);
extern s32 func_003C4F08();
extern f32 func_0038DF80(f32, f32);
extern f32 func_0038D540(f32, f32);
extern f32 func_0038D2B8(f32 *);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern void func_0038D348(void *, void *, f32);
s32 func_003C6720(void *, f32 *, f32 *, f32, f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C6720);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C6978);

typedef int Q_3C1130 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C1130;
typedef struct { f32 v[3]; } F3_3C1130;
typedef struct { u8 p0[0x10]; V_3C1130 f10; u8 p20[0x14]; u16 f34; u8 p36[0x8A]; u8 fC0[0x30]; V_3C1130 fF0; } O_3C1130;
typedef struct {
    V_3C1130 f0; V_3C1130 f10; V_3C1130 f20; u8 p30[0x18];
    f32 f48[3]; f32 f54[3]; f32 f60[3]; f32 f6C[3]; f32 f78[3]; f32 f84[3]; f32 f90[3]; f32 f9C[3];
} C_3C1130;
extern const F3_3C1130 D_001D91F0;
extern const F3_3C1130 D_001D9200;
extern const F3_3C1130 D_001D9210;
extern const F3_3C1130 D_001D9220;
extern const F3_3C1130 D_001D9230;
extern const F3_3C1130 D_001D9240;
extern void func_0038D3E0(void *, void *, void *);
extern f32 func_00382918(void);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C6A38);

typedef int Q_3C1440 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C1440;
typedef struct { u8 p0[0x10]; V_3C1440 pos; u8 p20[0xA0]; u8 fC0[0x30]; V_3C1440 fF0; } O_3C1440;
typedef struct {
    V_3C1440 f0; V_3C1440 f10; u8 f20[0x10]; f32 f30[3]; f32 f3C[3]; f32 f48[3]; f32 f54[3];
    f32 f60; f32 f64; f32 f68; f32 f6C; f32 f70; f32 f74; f32 f78[3]; f32 f84[3]; f32 f90[3]; f32 f9C[3]; s32 fA8; s32 fAC;
} C_3C1440;
typedef struct { u8 p0[0x80]; V_3C1440 f80; u8 p90[0x2CC]; O_3C1440 *f35C; s32 f360; } W_3C1440;
extern W_3C1440 D_1A4BE0;
extern s32 func_0011A264(void *, s32, s32);
extern void func_003C5418();
extern s32 func_0038CEB0(void *);
extern f32 func_0038DE98_003C6D48(f32, f32);
extern f32 func_0038D490(f32);
extern void func_0038D6E8();
extern void func_0038D9D0();
extern void func_0038D3E0(void *, void *, void *);
extern void func_003C56B0(void *, void *, void *, f32);
extern s32 func_003C5110();
extern void func_003C5160();
#define VSUB_3C1440(d, a, b) { Q_3C1440 p, q; __asm__("lqc2 %0, %1" : "=j"(p) : "m"(a)); __asm__("lqc2 %0, %1" : "=j"(q) : "m"(b)); __asm__("vsub.xyz %0, %1, %2" : "=j"(p) : "j"(p), "j"(q)); __asm__("sqc2 %1, %0" : "=m"(d) : "j"(p)); }
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C6D48);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C7200);

/* localdecomp:start func_003C7258 */
typedef struct { u16 id; u16 t; } E_C1950;
typedef struct { u8 p0[0x10]; u8 k; u8 p11; u8 n; u8 p13[9]; E_C1950 e[1]; } Y_C1950;
typedef struct { u8 p0[0xC]; u8 cnt; u8 pD[0x3B]; Y_C1950 *y[1]; } X_C1950;
typedef struct { u8 p0[0x24]; X_C1950 *x; } O_C1950;
void func_003C7258(O_C1950 *o, s32 idx, u16 t) {
    X_C1950 *x = o->x;
    Y_C1950 *y;
    E_C1950 *e;
    s32 i;
    if (x != 0 && idx < x->cnt) {
        y = x->y[idx];
        if (y->n != 0) {
            e = (E_C1950 *)((u8 *)y + (y->k * 4 + 0x1C));
            for (i = 0; i < y->n && (t << 4) >= e[i].t; i++) {
                func_003A56A0(e[i].id, 0, o);
            }
        }
    }
}
/* localdecomp:end func_003C7258 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C7330);

/* localdecomp:start func_003C7348 */
unsigned long func_003C7348(u8 *p, unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    register unsigned long shifted __asm__("$5") = a << 32;
    __asm__ volatile("" : "+r"(shifted));
    c <<= 8;
    d <<= 16;
    __asm__ volatile("" : "+r"(d));
    return *(unsigned long *)(p + 0x38) = shifted | b | c | d;
}
/* localdecomp:end func_003C7348 */
