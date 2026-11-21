#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AAD90 */
extern char D_001D8160[];
extern void func_003AACC8();
void func_003AAD90(u8 *p) {
    *(void **)(p + 4) = D_001D8160;
    func_003AACC8(p);
}
/* localdecomp:end func_003AAD90 */

typedef struct K_3A54A0 { struct K_3A54A0 *next; u8 p4[4]; f32 t; f32 v[4]; } K_3A54A0;
typedef struct { u8 p0[0xC]; K_3A54A0 *k; u32 n; s32 mode; } H_3A54A0;
typedef struct { u8 p0[8]; H_3A54A0 *h; } O_3A54A0;
/* localdecomp:start func_003AADB8 */
typedef struct Key_335960 {
    struct Key_335960 *next;
    int unknown;
    float time;
    float value[4];
} Key_335960;
typedef struct { char pad[12]; Key_335960 *first; unsigned int count; int mode; } Track_335960;
typedef struct { char pad[8]; Track_335960 *track; } Owner_335960;

void func_003AADB8(Owner_335960 *owner, float *out, float time) {
    Key_335960 *key, *previous;
    unsigned int i;
    float t;
    if (owner->track->count == 0) return;
    if (owner->track->count == 1) {
        out[0] = owner->track->first->value[0];
        out[1] = owner->track->first->value[1];
        out[2] = owner->track->first->value[2];
        out[3] = owner->track->first->value[3];
        return;
    }
    key = owner->track->first;
    previous = key;
    for (i = 0; i < owner->track->count; i++) {
        if (key->next != 0 && key->time <= time) {
            previous = key;
            key = key->next;
        } else {
            break;
        }
    }
    t = (time - previous->time) / (key->time - previous->time);
    switch (owner->track->mode) {
    case 0: case 1:
        out[0] = (1.0f-t)*previous->value[0] + t*key->value[0];
        out[1] = (1.0f-t)*previous->value[1] + t*key->value[1];
        out[2] = (1.0f-t)*previous->value[2] + t*key->value[2];
        out[3] = (1.0f-t)*previous->value[3] + t*key->value[3];
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_003AADB8 */

/* localdecomp:start func_003AAF20 */
extern u8 D_001D8178[];

void func_003AAF20(void *a0) {
    register void *dest __asm__("$2");    // $v0 ($2)
    register s32 val __asm__("$3");       // $v1 ($3)

    // Force the exact 64-bit move instruction (daddu) at offset 0.
    // This generates the exact machine code bytes for 0x0080102d.
    __asm__ volatile("daddu %0, %1, $0" : "=r"(dest) : "r"(a0));

    val = (s32)&D_001D8178;

    __asm__ volatile("" : : "r"(dest), "r"(val));

    *(s32 *)dest = val;
}
/* localdecomp:end func_003AAF20 */

/* localdecomp:start func_003AAF38 */
extern u8 D_001D8178[];
extern s32 func_003F2738();
void func_003AAF38(void **p, s32 f) { *p = D_001D8178; if (f & 1) func_003F2738(p); }
/* localdecomp:end func_003AAF38 */

/* localdecomp:start func_003AAF68 */
void func_003AAF68(s32 unused, f32 *out, f32 *a, f32 *b, f32 t) {
    f32 s = 1.0f - t;
    out[0] = s * a[0] + t * b[0];
    out[1] = s * a[1] + t * b[1];
    out[2] = s * a[2] + t * b[2];
    out[3] = s * a[3] + t * b[3];
}
/* localdecomp:end func_003AAF68 */

/* localdecomp:start func_003AAFD8 */
extern s32 func_0038DFB8(f32, s32, s32);
void func_003AAFD8(f32 f, s32 x, s32 *out, s32 *a, s32 *b) {
    out[0] = func_0038DFB8(f, a[0], b[0]);
    out[1] = func_0038DFB8(f, a[1], b[1]);
    out[2] = func_0038DFB8(f, a[2], b[2]);
    out[3] = func_0038DFB8(f, a[3], b[3]);
}
/* localdecomp:end func_003AAFD8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB068);

/* localdecomp:start func_003AB078 */
extern f32 func_003AF658(f32, f32, f32, f32, f32);
void func_003AB078(u8 *p, f32 *out, f32 t) {
    *out = func_003AF658(t, 0.0f, *(f32 *)(p + 8), *(f32 *)(p + 0xC), 1.0f);
}
/* localdecomp:end func_003AB078 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB0B8);

/* localdecomp:start func_003AB0C8 */
extern u8 D_001D80E8[];
extern void func_003AC300();
extern void func_003AACC8();
void func_003AB0C8(u8 *p, s32 f) {
    *(void **)(p + 4) = D_001D80E8;
    func_003AC300(*(void **)(p + 0x2C), *(s32 *)(p + 0x28));
    func_003AACC8(p, f);
}
/* localdecomp:end func_003AB0C8 */

/* localdecomp:start func_003AB118 */
void func_003AB118(f32 *a, f32 *out, f32 t) {
    f32 s = 1.0f - t;
    out[0] = s * a[2] + t * a[3];
    out[1] = s * a[4] + t * a[5];
    out[2] = s * a[6] + t * a[7];
    out[3] = s * a[8] + t * a[9];
}
/* localdecomp:end func_003AB118 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB188);

/* localdecomp:start func_003AB198 */
extern void func_003AACC8();
void func_003AB198(void) {
    func_003AACC8();
}
/* localdecomp:end func_003AB198 */

/* localdecomp:start func_003AB1B8 */
extern void func_003AACC8();
void func_003AB1B8(void) {
    func_003AACC8();
}
/* localdecomp:end func_003AB1B8 */

extern s32 D_001D8118[];
extern void func_003AAF38();

/* localdecomp:start func_003AB1D8 */
extern s32 D_001D8118[2];
extern void func_003AAF38();
void func_003AB1D8(void **p, s32 f) {
    *p = D_001D8118;
    func_003AAF38(p, f);
}
/* localdecomp:end func_003AB1D8 */

extern s32 D_001D8100[];
extern void func_003AAF38();

/* localdecomp:start func_003AB1F8 */
extern s32 D_001D8100[2];
extern void func_003AAF38();
void func_003AB1F8(void **p, s32 f) {
    *p = D_001D8100;
    func_003AAF38(p, f);
}
/* localdecomp:end func_003AB1F8 */
