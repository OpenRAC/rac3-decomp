#include "common.h"

typedef struct {
    s32 v[10];
} S_003FF4E8;

typedef struct WeightTap_00400390 {
    u8 row;
    u8 col;
    s16 weight;
} WeightTap_00400390;

typedef struct {
    char pad00[0x22];
    s16 f22;
    char pad24[0x8];
    s32 f2C;
    char pad30[0x340];
    s32 f370;
    s32 f374;
} S_004001E8;

INCLUDE_ASM("asm/levels", func_L01_003FE908);

/* localdecomp:start func_L01_003FE938 */
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001EA940[];
extern s32 D_L01_001DF948;
extern s32 D_L01_001E1070;
extern s32 D_L01_001D66A4;
extern s32 D_L01_001D4BB4;
extern f32 D_L01_001DF950;
extern void func_003A92F0(s32);
extern s32 func_0012C908(s32);
extern void func_003A9108(void);
extern void func_003A5430(void);

/* from rac2-decomp's func_00278EB0 */
void func_L01_003FE938(void) {
    s32 *state;
    s32 x, y, z;
    func_003A92F0(1);
    func_0012C908(0);
    D_L01_001DF948++;
    y = D_L01_001EA940[4];
    x = D_L01_001EA940[3];
    z = D_L01_001E1070;
    state = D_L01_001E64C0;
    state[5] = z - 0x60000;
    D_L01_001E1070 = 0x60000;
    state[0] = x + 0x60000;
    state[1] = y + 0x60000;
    state[2] = state[0] + 0xD0800;
    D_L01_001D66A4 = 0x2000;
    func_003A9108();
    func_003A5430();
    state[6] = D_L01_001D4BB4;
    D_L01_001DF950 = 1.0f;
}
/* localdecomp:end func_L01_003FE938 */

/* localdecomp:start func_L01_003FEA00 */
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001D4BB4;
extern s32 D_001D4CEC_sda;
__asm__(".extern D_L01_001D4BB4, 4");
__asm__(".extern D_001D4CEC_sda, 4");
void func_L01_003FEA00(void) {
    extern void func_003A92F0(s32);
    extern void func_003A9050(void);
    extern void func_003A9108(void);
    extern void func_0038A238(s32);
    extern s32 func_003A0EA8(s32);
    u8 *g;
    func_003A92F0(1);
    func_003A9050();
    func_003A9108();
    g=(u8 *)D_L01_001E64C0;
    D_L01_001D4BB4=*(s32 *)(g+0x18);
    func_0038A238(30);
    if(func_003A0EA8(4) && (D_001D4CEC_sda&1)) *(s16 *)(g+0x28)=0;
}
/* localdecomp:end func_L01_003FEA00 */

INCLUDE_ASM("asm/levels", func_L01_003FEA68);

INCLUDE_ASM("asm/levels", func_L01_003FF240);

/* localdecomp:start func_L01_003FF4E8 */
extern S_003FF4E8 D_L01_001E6850[];

void func_L01_003FF4E8(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5,
                       s32 p6, s32 p7, s32 p8, s32 p9, u32 idx)
{
    if (idx >= 32u)
        return;
    D_L01_001E6850[idx].v[0] = p0;
    D_L01_001E6850[idx].v[1] = p1;
    D_L01_001E6850[idx].v[2] = p2;
    D_L01_001E6850[idx].v[3] = p3;
    D_L01_001E6850[idx].v[4] = p4;
    D_L01_001E6850[idx].v[5] = p5;
    D_L01_001E6850[idx].v[6] = p6;
    D_L01_001E6850[idx].v[7] = p7;
    D_L01_001E6850[idx].v[8] = p8;
    D_L01_001E6850[idx].v[9] = p9 * 37 + 200;
}
/* localdecomp:end func_L01_003FF4E8 */

INCLUDE_ASM("asm/levels", func_L01_003FF570);

INCLUDE_ASM("asm/levels", func_L01_003FF9F0);

/* localdecomp:start func_L01_003FFC88 */
typedef struct {
    char pad00[0x22];
    s16 f22;
    char pad24[0x364];
    s32 f388;
} S_003FFC88;
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001D4BC0;
extern s32 D_L01_001D60B8;
__asm__(".extern D_L01_001D60B8, 4");
extern s32 func_L01_00400160(s32 a0, s32 *a1, s32 *a2);
extern s32 func_L01_004000C0(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30_003FFC88(s32, s32, s32, s32, unsigned long);
extern void func_003910C0(void *,s32,s32,s32,s32,s32,s32,s32,s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038FA18(void *,s32,s32,s32,long,f32,f32);

void func_L01_003FFC88(s32 row, f32 t) {
    s32 rect[8];
    s32 entry, offset;
    s32 text;
    s32 y;
    S_003FFC88 *g;
    if (func_L01_00400160(row, &entry, &offset)) {
        text = func_L01_004000C0(D_L01_001E6850[entry].v[1] + offset);
        if (text) {
            func_003A9440(0x47, 0x33001);
            g = (S_003FFC88 *)D_L01_001E64C0;
            y = D_L01_001E6850[g->f22].v[5] + row * D_L01_001E6850[g->f22].v[8];
            func_0038AF30_003FFC88(y + 2, y + D_L01_001E6850[g->f22].v[8] - 2,
                                   0, D_L01_001D4BC0, (s32)(t * 96.0f) << 24);
            func_003910C0(rect, y, y + D_L01_001E6850[g->f22].v[8], 0, D_L01_001D4BC0, D_L01_001D4BC0 / 2 + 2,
                          y + D_L01_001E6850[g->f22].v[8] / 2 + 1, g->f388, 3);
            func_0038FA18(rect, func_0038DBD8(0, 0x80000000, t), text, -1, 0x80000000L, 1.0f, 1.0f);
            func_003910C0(rect, y, y + D_L01_001E6850[g->f22].v[8], 0, D_L01_001D4BC0, D_L01_001D4BC0 / 2,
                          y + D_L01_001E6850[g->f22].v[8] / 2, g->f388, 3);
            func_0038FA18(rect, func_0038DBD8(D_L01_001D60B8 & 0xFFFFFF, D_L01_001D60B8, t), text, -1, 0x80000000L, 1.0f, 1.0f);
        }
    }
}
/* localdecomp:end func_L01_003FFC88 */

/* localdecomp:start func_L01_003FFED0 */
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001D4BC0;
extern s32 D_L01_001D60B8;
__asm__(".extern D_L01_001D60B8, 4");
void func_L01_003FFED0(void) {
    extern s32 func_L01_004000C0(s32);
    extern void func_003910C0(void *,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_0038FA18(void *,s32,s32,s32,long,f32,f32);
    extern void func_0038AF30(s32,s32,s32,s32,u32);
    s32 rect[8];
    s32 text;
    s32 end,start,i,divisor;
    text=func_L01_004000C0(D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[0]);
    if(text) {
        { S_004001E8 *g=(S_004001E8 *)D_L01_001E64C0;
        func_003910C0(rect,0,D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[5],0,D_L01_001D4BC0,D_L01_001D4BC0/2,D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[4],18,1);
        func_0038FA18(rect,D_L01_001D60B8,text,-1,0x80000000L,1.0f,1.0f);
        }
        end=D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[5]-2;
        start=D_L01_001E6850[((S_004001E8 *)D_L01_001E64C0)->f22].v[5]-4;
        divisor=6;
        for(i=5;i>=0;i--) {
            func_0038AF30(end-start,end,-D_L01_001D4BC0,D_L01_001D4BC0*2,0x18000000);
            start=start*5/divisor;
        }
        { S_004001E8 *g=(S_004001E8 *)D_L01_001E64C0;
        func_003910C0(rect,0,D_L01_001E6850[g->f22].v[5],0,D_L01_001D4BC0,D_L01_001D4BC0/2,D_L01_001E6850[g->f22].v[4],18,1);
        func_0038FA18(rect,D_L01_001D60B8,text,-1,0x80000000L,1.0f,1.0f);
        }
    }
}
/* localdecomp:end func_L01_003FFED0 */

/* localdecomp:start func_L01_004000C0 */
typedef struct {
    s32 value;          
    s32 key;            
    char pad08[8];
} Rec_2e36f8;
extern s32 D_L01_001E64C0[];

/* from rac2-decomp's func_L00_002E36F8, renamed */
s32 func_L01_004000C0(s32 key)
{
    Rec_2e36f8 *entry;
    s32 count = D_L01_001E64C0[4];
    s32 i;
    if (count > 0) {
        i = 0;
        entry = (Rec_2e36f8 *)D_L01_001E64C0[3];
        do {
            if (entry->key == key)
                return entry->value;
            entry++;
            i++;
        } while (i < count);
    }
    return 0;
}
/* localdecomp:end func_L01_004000C0 */

/* localdecomp:start func_L01_00400100 */
void func_L01_00400100(void) {
    s32 i;

    D_L01_001E64C0[3] = D_L01_001E64C0[2];
    D_L01_001E64C0[4] = *(u32 *)D_L01_001E64C0[3] >> 4;
    for (i = 0; i < D_L01_001E64C0[4]; i++) {
        ((Rec_2e36f8 *)D_L01_001E64C0[3])[i].value += D_L01_001E64C0[3];
    }
}
/* localdecomp:end func_L01_00400100 */

/* localdecomp:start func_L01_00400160 */
s32 func_L01_00400160(s32 a0, s32 *a1, s32 *a2) {
    u8 *g = (u8 *)D_L01_001E64C0;

    *a1 = *(s16 *)(g + 0x22);
    *a2 = *(s16 *)(g + 0x24) + a0;
    if (*a1 >= 0 && *a1 < D_L01_001E6850[32].v[0]) {
        return !(D_L01_001E6850[*a1].v[2] < D_L01_001E6850[*a1].v[1] + *a2);
    }
    return 0;
}
/* localdecomp:end func_L01_00400160 */

/* localdecomp:start func_L01_004001C8 */
void func_0038CAD0(void *);
extern u8 D_L01_001E64EC[];

void func_L01_004001C8(void) {
    func_0038CAD0(D_L01_001E64EC);
}
/* localdecomp:end func_L01_004001C8 */

/* localdecomp:start func_L01_004001E8 */
extern s32 D_L01_001E64C0[];
extern s16 D_L01_001E64E8[];
extern s32 func_L01_00400280(void);

void func_L01_004001E8(void)
{
    S_004001E8 *g;
    s32 v;
    if (func_L01_00400280() != 0) {
        g = (S_004001E8 *)D_L01_001E64C0;
        v = D_L01_001E6850[g->f22].v[6];
        if (v == 0) {
            g->f2C = D_L01_001E6850[g->f22].v[9];
        } else if (v >= 0) {
            if (v < 3) {
                g->f2C = g->f374 + g->f370 * (D_L01_001E6850[g->f22].v[7] - 1);
            }
        }
    } else {
        D_L01_001E64E8[0] = 5;
    }
}
/* localdecomp:end func_L01_004001E8 */

/* localdecomp:start func_L01_00400280 */
s32 func_L01_00400280(void) {
    extern s32 func_L01_00400160(s32 a0, s32 *a1, s32 *a2);
    s32 a, b;
    S_004001E8 *g = (S_004001E8 *)D_L01_001E64C0;
    if (g->f22 == -1) {
        g->f22 = 0;
        ((s16 *)g)[18] = 0;
        return 1;
    }
    if (func_L01_00400160(D_L01_001E6850[g->f22].v[7], &a, &b)) {
        if (D_L01_001E6850[g->f22].v[7] != 0) {
            g->f22 = a;
            ((s16 *)g)[18] = b;
            return 1;
        }
    }
    ((S_004001E8 *)D_L01_001E64C0)->f22++;
    ((s16 *)D_L01_001E64C0)[18] = 0;
    return ((S_004001E8 *)D_L01_001E64C0)->f22 < D_L01_001E6850[32].v[0];
}
/* localdecomp:end func_L01_00400280 */

/* localdecomp:start func_L01_00400368 */
/* from rac2-decomp's func_L00_002E3A68, renamed */
s32 func_L01_00400368(f32 a,f32 b,f32 t) {
 f32 difference=b-a;
 f32 squared=t*t;
 a=a*t;
 difference=difference*squared;
 a=a+difference;
 return (s32)a;
}
/* localdecomp:end func_L01_00400368 */

/* localdecomp:start func_L01_00400390 */
extern u8 D_00142692[];
extern WeightTap_00400390 D_L01_002C0160[][16][10];
extern s32 D_1C5290[][16];

s32 func_L01_00400390(s32 a0, s32 a1) {
    WeightTap_00400390 *tap;
    s32 sum;
    s32 n;

    if (D_00142692[0] != 0) {
        return 0;
    }
    if (a0 >= 30) {
        return 0;
    }
    if (a1 >= 16) {
        return 0;
    }
    tap = D_L01_002C0160[a0][a1];
    sum = 0;
    for (n = 9; n >= 0; n--) {
        sum += tap->weight * D_1C5290[tap->row][tap->col];
        tap++;
    }
    return sum;
}
/* localdecomp:end func_L01_00400390 */

/* localdecomp:start func_L01_00400430 */
extern u8 D_00142692[];
extern s32 D_001D545C;
extern s32 func_L01_00400390(s32 a0, s32 a1);
s32 func_L01_00400430(s32 a0) {
    u8 s = D_00142692[0];
    s32 v;
    if (s != 0) {
        return 3;
    }
    v = 3 - func_L01_00400390(D_001D545C, a0) / 100;
    if (s < v) {
        return v;
    }
    return 1;
}
/* localdecomp:end func_L01_00400430 */

/* localdecomp:start func_L01_00400490 */
extern u8 D_00142692[];
extern s32 D_001D545C;          /* the level number: no size hint, so Ps2EeAs reads it with `lui` here */
extern WeightTap_00400390 D_L01_002C0160[][16][10];

/* help_checkpoint_refund: 100 / the area's first help weight, rounded up; 0 in challenge mode. */
s32 func_L01_00400490(s32 area) {
    WeightTap_00400390 *tap;
    s32 refund;

    if (D_00142692[0] != 0) {
        return 0;
    }
    tap = D_L01_002C0160[D_001D545C][area];
    refund = 100 / tap->weight;
    if (100 % tap->weight != 0) {
        return refund + 1;
    }
    return refund;
}
/* localdecomp:end func_L01_00400490 */

/* localdecomp:start func_L01_004004F8 */
typedef struct { u8 pad[0x46]; u8 kind; } Parent_004004F8;
typedef struct {
    u8 pad[0x24]; Parent_004004F8 *parent;
    u8 pad28[0x82]; s16 kind;
} Object_004004F8;
typedef struct {
    f32 value; s16 amount; u8 pad06[0xE]; u8 color[3];
} Result_004004F8;
extern u8 D_00142692[];
extern u8 D_0014275B[];
extern s32 D_001D545C;
extern f32 D_L01_002F16F0[];
extern f32 D_L01_002F1510[];
extern f32 D_L01_001DAA38;
extern f32 D_L01_001DAA30;
__asm__(".extern D_L01_001DAA38, 4");
__asm__(".extern D_L01_001DAA30, 4");
void func_L01_004004F8(Object_004004F8 *obj) {
    extern Result_004004F8 *func_00382348(void);
    Result_004004F8 *r;
    f32 amount_scale, color_scale;
    s32 p, end;
    s32 n;
    s32 limit;
    if (D_00142692[0] == 0) return;
    if (obj->kind == 500 || obj->kind == 502 || obj->kind == 505 || obj->kind == 512) return;
    if (D_001D545C >= 60) return;
    r = func_00382348();
    if (r == 0) return;
    if (obj->parent != 0 && obj->parent->kind == 13) {
        amount_scale = D_001D545C == 7 && D_0014275B[0] ? D_L01_001DAA38 : D_L01_002F16F0[D_001D545C];
        color_scale = D_001D545C == 7 && D_0014275B[0] ? D_L01_001DAA30 : D_L01_002F1510[D_001D545C];
    } else {
        amount_scale = D_001D545C == 7 && D_0014275B[0] ? D_L01_001DAA30 : D_L01_002F1510[D_001D545C];
        color_scale = D_001D545C == 7 && D_0014275B[0] ? D_L01_001DAA38 : D_L01_002F16F0[D_001D545C];
    }
    limit = 255;
    p = (s32)r->color;
    r->amount = (s32)(r->amount * amount_scale);
    r->value = r->amount;
    end = p + 3;
    do {
        n = (s32)(*(u8 *)p * color_scale);
        if (n >= 256) n = limit;
        *(u8 *)p = n;
        p++;
    } while (p < end);
}
/* localdecomp:end func_L01_004004F8 */

/* localdecomp:start func_L01_004006C8 */
extern u8 D_1BBE90[][1024];

s32 func_L01_004006C8(u8 *a0, s32 a1, s32 a2) {
    s32 c = D_1BBE90[*(s32 *)0x1D545C][a2 >> 1];

    return (a0[(a2 & 1) ? ((c >> 4) & 7) : (c & 7)] * a1) / 100;
}
/* localdecomp:end func_L01_004006C8 */
