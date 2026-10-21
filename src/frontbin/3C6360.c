#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A52A0();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003C6360);

typedef int Q_3C0E10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C0E10;
typedef struct { u8 p0[0x10]; V_3C0E10 pos; } O_3C0E10;
typedef struct { u8 p0[0x46]; u8 b46; } P_3C0E10;
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; u8 p18[0xC]; P_3C0E10 *f24; } E_3C0E10;
extern E_3C0E10 *D_0022B6C0[];
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_003C4B50();
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
s32 func_003C6368(void *, f32 *, f32 *, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C6368);

LINKER_REMNANT("asm/remnants", func_003C65C0);

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
extern void func_0038D000(void *, void *, void *);
extern f32 func_00382538(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003C6680);

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
extern void func_003C5060();
extern s32 func_0038CAD0(void *);
extern f32 func_0038DAB8_003C6990(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D308();
extern void func_0038D5F0();
extern void func_0038D000(void *, void *, void *);
extern void func_003C52F8(void *, void *, void *, f32);
extern s32 func_003C4D58();
extern void func_003C4DA8();
#define VSUB_3C1440(d, a, b) { Q_3C1440 p, q; __asm__("lqc2 %0, %1" : "=j"(p) : "m"(a)); __asm__("lqc2 %0, %1" : "=j"(q) : "m"(b)); __asm__("vsub.xyz %0, %1, %2" : "=j"(p) : "j"(p), "j"(q)); __asm__("sqc2 %1, %0" : "=m"(d) : "j"(p)); }
INCLUDE_ASM("asm/nonmatchings/text", func_003C6990);

LINKER_REMNANT("asm/remnants", func_003C6E48);

/* localdecomp:start func_003C6EA0 */
typedef struct { u16 id; u16 t; } E_C1950;
typedef struct { u8 p0[0x10]; u8 k; u8 p11; u8 n; u8 p13[9]; E_C1950 e[1]; } Y_C1950;
typedef struct { u8 p0[0xC]; u8 cnt; u8 pD[0x3B]; Y_C1950 *y[1]; } X_C1950;
typedef struct { u8 p0[0x24]; X_C1950 *x; } O_C1950;
void func_003C6EA0(O_C1950 *o, s32 idx, u16 t) {
    X_C1950 *x = o->x;
    Y_C1950 *y;
    E_C1950 *e;
    s32 i;
    if (x != 0 && idx < x->cnt) {
        y = x->y[idx];
        if (y->n != 0) {
            e = (E_C1950 *)((u8 *)y + (y->k * 4 + 0x1C));
            for (i = 0; i < y->n && (t << 4) >= e[i].t; i++) {
                func_003A52A0(e[i].id, 0, o);
            }
        }
    }
}
/* localdecomp:end func_003C6EA0 */

LINKER_REMNANT("asm/remnants", func_003C6F78);

/* localdecomp:start func_003C6F90 */
unsigned long func_003C6F90(u8 *p, unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    register unsigned long shifted __asm__("$5") = a << 32;
    __asm__ volatile("" : "+r"(shifted));
    c <<= 8;
    d <<= 16;
    __asm__ volatile("" : "+r"(d));
    return *(unsigned long *)(p + 0x38) = shifted | b | c | d;
}
/* localdecomp:end func_003C6F90 */
