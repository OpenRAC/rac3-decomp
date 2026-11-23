#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* declared by functions of L01_004A32E0.c, which this file was cut from */
extern void func_L01_004A3B88(void);

/* localdecomp:start func_L01_004A3A90 */
/* Ported from rac4-decomp/src/overlays/shared/L00_00665120.c. */
extern Type_004A3A90 *D_L01_001E001C;
extern Type_004A3A90 *D_L01_001E0020;
__asm__(".extern D_L01_001E001C, 16");
__asm__(".extern D_L01_001E0020, 16");
u8 *func_L01_004A3A90(s32 unused, s32 id) {
    Type_004A3A90 *p;
    for (p = D_L01_001E001C; p != D_L01_001E0020; p++) {
        if (p->fB2 == id) {
            return (u8 *)p;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_004A3A90 */

/* localdecomp:start func_L01_004A3AD0 */


extern u8 *func_L01_004A3A90(s32 a, s32 b);
extern void func_0038CC88(void *dst, void *src, s32 size);

void func_L01_004A3AD0(Table_4A0270 *table) {
    s32 i;
    for (i = 0; i < table->count; i++) {
        Entry_4A0270 *e = &table->entries[i];
        u8 *obj = func_L01_004A3A90(e->arg0, e->arg1);
        if (obj != 0) {
            u8 *dst;
            if (e->kind == 1) {
                dst = (u8 *)e->offset + (s32)obj;
            } else {
                dst = (u8 *)e->offset + *(s32 *)(obj + 104);
            }
            func_0038CC88(dst, &e->data, e->size);
        }
    }
}
/* localdecomp:end func_L01_004A3AD0 */

/* localdecomp:start func_L01_004A3B88 */
extern u8 D_L01_00237860[];
extern void func_L01_004A3AD0_004A3B88(void *a0);

void func_L01_004A3B88(void) {
    func_L01_004A3AD0_004A3B88(D_L01_00237860);
}
/* localdecomp:end func_L01_004A3B88 */
