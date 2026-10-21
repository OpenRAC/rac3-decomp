#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BB468(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003BB478();
extern void func_003BB480();
extern void func_003BA8B0(void *, s32);
extern s32 *func_003B9F88(s32);
extern s32 func_003BA010(s32 *);
extern s32 func_003BA020();
extern void func_003BAF68(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003BAF88(void *, f32, f32, f32, f32);
extern void func_003BA898(void *, s32, f32, f32, f32);
extern void func_003BA710();
extern void func_003BB308();
extern s32 func_003BB478(void);
extern void func_003BB480(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B9F88 */
typedef struct { u8 b[0xB4]; } E_3B46F0;
extern E_3B46F0 D_00280CF0[];
extern s32 D_001DA1A8;
extern void func_003B9E48(E_3B46F0 *);
s32 *func_003B9F88(s32 idx) {
    s32 i;
    E_3B46F0 *p;
    if (D_001DA1A8 == 0) {
        p = D_00280CF0;
        i = 3;
        do { func_003B9E48(p); i--; __asm__ volatile("nop"); p++; } while (i != -1);
        D_001DA1A8 = 1;
    }
    return (s32 *)&D_00280CF0[idx];
}
/* localdecomp:end func_003B9F88 */

/* localdecomp:start func_003BA010 */
s32 func_003BA010(s32 *p) {
    return p[1] + p[2];
}
/* localdecomp:end func_003BA010 */

/* localdecomp:start func_003BA020 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B4788;
typedef struct { u8 f0; u8 p1[3]; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; s32 f58; u8 p5C[0x4C]; u8 fA8; u8 fA9; u8 pAA[2]; f32 fAC; s32 fB0; } O_3B4788;
extern void func_003BA280();
extern void func_0038CF58();
extern void func_003BA6F8();
s32 func_003BA020(O_3B4788 *o, S_3B4788 *s) {
    s32 size;
    s32 ret = 1;
    s32 i, j, k;
    o->fA8 = 0;
    o->fA9 = 0;
    { s32 t = s->fC * 0x44; size = s->f14 * t; }
    if (size >= s->f0) {
        ret = 0;
    } else {
        o->f4 = 0;
        o->f8 = 0;
        o->fC = s->fC;
        o->f10 = s->f10;
        o->f14 = s->f14;
        o->f18 = s->f8;
        o->f1C = 0;
        for (k = 0; k < 4; k++) {
            o->a20[k] = s->a24[k];
            o->a30[k] = s->a44[k];
            o->a40[k] = s->a34[k];
        }
        o->f50 = s->f1C;
        o->f54 = s->f20;
        o->fAC = s->f18;
        o->fB0 = s->f4;
        func_003BA280(o);
        o->f0 = 1;
    }
    func_0038CF58(o->fB0, 0, size);
    for (i = 0; i < o->f14; i++) {
        for (j = 0; j < o->fC; j++) {
            *(s32 *)((u8 *)func_003BA1E8(o, i, j) + 0x40) = 0;
        }
    }
    func_003BA6F8(o, 0x8066CCFF, 0x80808080, 0x666690CC, 0x80FFFFFF);
    o->f58 = 0;
    return ret;
}
/* localdecomp:end func_003BA020 */

/* localdecomp:start func_003BA1E8 */
s32 func_003BA1E8(void *p, s32 x, s32 y) {
    return *(s32 *)((u8 *)p + 0xB0) + (*(s32 *)((u8 *)p + 0x14) * y + x) * 0x44;
}
/* localdecomp:end func_003BA1E8 */

/* localdecomp:start func_003BA208 */
s32 func_003BA208(void *p, s32 x, s32 y) {
    y += 0x4F0000;
    return x * (*(s32 *)((u8 *)p + 0x14) * *(s32 *)((u8 *)p + 0x10)) + y;
}
/* localdecomp:end func_003BA208 */

/* localdecomp:start func_003BA228 */
s32 func_003BA228(s32 a0, s32 a1) {
    return a1 + 0x4F0048;
}
/* localdecomp:end func_003BA228 */

/* localdecomp:start func_003BA238 */
s32 func_003BA238(s32 a0, s32 a1) {
    return a1 + 0x4F00A9;
}
/* localdecomp:end func_003BA238 */

/* localdecomp:start func_003BA248 */
extern s32 func_003E8960();
 
s32 func_003BA248(u8 *p) {
    s32 r = 0;
    if (p[0] != 0) {
        p[0] = 0;
        func_003E8960(*(s32 *)(p + 0x18));
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003BA248 */

typedef struct { u8 p0[0x10]; s32 f10; s32 f14; s32 f18; u8 p1C[4]; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; u8 p58[4]; f32 f5C; f32 f60; u8 p64[8]; f32 f6C; f32 f70; u8 p74[0x28]; u32 f9C; f32 fA0; f32 fA4; u8 pA8[4]; f32 fAC; } S_3B49E8;
extern void func_003E9808();
extern s32 func_003E85A8(s32, f32, f32);
extern void func_003E91D0_003BA280(s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8C50(s32, f32, f32);
extern s32 func_003E8D10(s32, s32);
extern s32 func_003E7E80(s32, s32);
extern s32 func_003E94F0_003BA280(s32, u32, f32, f32, f32, f32, s32);
extern s32 func_003E92A8(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8DC0(s32, s32, s32);
extern s32 func_003E7DD0(s32, s32);
extern s32 func_003E8700(s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BA280);

/* localdecomp:start func_003BA6F8 */
void func_003BA6F8(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x8c) = a1;
    *(s32 *)((u8 *)a0 + 0x90) = a2;
    *(s32 *)((u8 *)a0 + 0x94) = a3;
    *(s32 *)((u8 *)a0 + 0x98) = a4;
}
/* localdecomp:end func_003BA6F8 */

/* localdecomp:start func_003BA710 */
extern s32 func_003BA208(void *, s32, s32);
extern s32 func_003E7CE0(s32, s32, s32);
typedef struct { u8 p[0x10]; s32 n; } S_B4E78;
void func_003BA710(S_B4E78 *s) {
    s32 i, t;
    for (i = 0; ; ) {
        t = s->n + 2;
        if (i >= t) break;
        func_003E7CE0(func_003BA208(s, 0, i), 1, 3);
        func_003E7CE0(func_003BA208(s, 1, i), 2, 3);
        i++;
    }
}
/* localdecomp:end func_003BA710 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BA7A0);

/* localdecomp:start func_003BA7A8 */
extern s32 func_003E7DD0(s32 arg0, s32 arg1);
void func_003BA7A8(u8 *p) {
    func_003E7DD0(0x4F00B0, p[0xA8]);
    func_003E7DD0(0x4F00B1, p[0xA8]);
}
/* localdecomp:end func_003BA7A8 */

/* localdecomp:start func_003BA7E8 */
extern s32 func_003BA228(s32, s32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E7DD0(s32, s32);
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x4C]; f32 x60; u8 p64[0x10]; u8 x74; u8 p75[0x2B]; f32 xA0; f32 xA4; } S_4F;
void func_003BA7E8(S_4F *a0) {
    f32 t = a0->x60 - a0->xA0;
    s32 i;
    if (t < 0.0f) t = 0.0f;
    for (i = 0; i < a0->x10 + 2; i++) {
        func_003E85A8(func_003BA228((s32)a0, i), t, a0->xA4);
        func_003E7DD0(func_003BA228((s32)a0, i), a0->x74);
    }
}
/* localdecomp:end func_003BA7E8 */

/* localdecomp:start func_003BA898 */
void func_003BA898(void *a0, s32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "sb $5, 0x74($4)\n"
        "swc1 $12, 0x70($4)\n"
        "swc1 $13, 0xa4($4)\n"
        :: "r"(a0), "r"(a1)
    );
    *(f32 *)((u8 *)a0 + 0xa0) = a4;
}
/* localdecomp:end func_003BA898 */

/* localdecomp:start func_003BA8B0 */
extern void func_003BA7E8();
extern void func_003BAA88(void *);
extern void func_003BAB48(void *);
extern void func_003BACD8(void *, s32);
extern void func_003BB090(void *);
extern void func_003BB988();
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E7B18(s32, f32);
extern s32 func_003E7DD0(s32 arg0, s32 arg1);
extern s32 func_003E85A8(s32, f32, f32);

void func_003BA8B0(void *arg0, s32 arg1) {
    func_003BA7A8(arg0);
    func_003BA9C0(arg0);
    func_003BAA88(arg0);
    func_003BAB48(arg0);
    func_003BB090(arg0);
    func_003BA7E8(arg0);
    func_003BB988();
    if ((*(s32 *)((u8 *)(arg0) + 0x1C)) == 0) {
        func_003BACD8(arg0, arg1);
    }
    func_003E7770(0x4F00A8, (*(f32 *)((u8 *)(arg0) + 0x7C)), (*(f32 *)((u8 *)(arg0) + 0x80)));
    func_003E85A8(0x4F00A8, (*(f32 *)((u8 *)(arg0) + 0x84)), (*(f32 *)((u8 *)(arg0) + 0x88)));
    func_003E7770(0x4F00B3, (*(f32 *)((u8 *)(arg0) + 0x7C)), (*(f32 *)((u8 *)(arg0) + 0x80)));
    func_003E85A8(0x4F00B3, (*(f32 *)((u8 *)(arg0) + 0x84)), (*(f32 *)((u8 *)(arg0) + 0x88)));
    func_003E7DD0(0x4F00B3, (*(u8 *)((u8 *)(arg0) + 0xA9)));
    func_003E7B18(0x4F00B0, (*(f32 *)((u8 *)(arg0) + 0x6C)));
    func_003E7B18(0x4F00B1, (*(f32 *)((u8 *)(arg0) + 0x6C)));
    func_003E85A8(0x4F00AF, (*(f32 *)((u8 *)(arg0) + 0x60)), (*(f32 *)((u8 *)(arg0) + 0x64)));
}
/* localdecomp:end func_003BA8B0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BA9C0);

/* localdecomp:start func_003BAA88 */
void func_003BAA88(void *arg0)
{
  f32 temp_f0;
  f32 temp_f1;
  s32 temp_2_2;
  s32 temp_2;
  s32 temp_3;
  s32 temp_4;
  s32 temp_5;
  s32 var_3;
  temp_f1 = *((f32 *) (((u8 *) arg0) + 0x58));
  temp_f0 = *((f32 *) (((u8 *) arg0) + 0x54));
  if ((temp_f0 < temp_f1) || (temp_f1 < (-temp_f0)))
  {
    temp_3 = *((s32 *) (((u8 *) arg0) + 0x1C));
    switch (temp_3)
    {
      case 3:

      case 1:
        temp_2 = (*((s32 *) (((u8 *) arg0) + 4))) + 1;
        *((s32 *) (((u8 *) arg0) + 4)) = temp_2;
        var_3 = temp_2;
        break;

      default:
        temp_2_2 = (*((s32 *) (((u8 *) arg0) + 4))) - 1;
        *((s32 *) (((u8 *) arg0) + 4)) = temp_2_2;
        var_3 = temp_2_2;
        break;

    }

    temp_4 = *((s32 *) (((u8 *) arg0) + 0xC));
    temp_5 = (var_3 > (-1)) ? (var_3) : (0);
    *((f32 *) (((u8 *) arg0) + 0x58)) = 0.0f;
    *((s32 *) (((u8 *) arg0) + 0x1C)) = 0;
    *((s32 *) (((u8 *) arg0) + 4)) = (s32) ((temp_5 < temp_4) ? (temp_5) : (temp_4 - 1));
  }
}
/* localdecomp:end func_003BAA88 */

/* localdecomp:start func_003BAB28 */
void func_003BAB28(s32 *p) {
    s32 c = p[3];
    if (p[1] >= c) {
        p[1] = c - 1;
    }
}
/* localdecomp:end func_003BAB28 */

/* localdecomp:start func_003BAB48 */
typedef struct {
    u8 p0[0x10]; s32 f10; s32 f14; u8 p18[8]; f32 f20[12];
    f32 f50; f32 f54; f32 f58; f32 f5C; u8 p60[0x10]; f32 f70; u8 p74[4]; f32 f78; u8 p7C[0x20]; u32 f9C;
} S_3B52B0;
void func_003BAB48(void *arg0) {
    S_3B52B0 *o = arg0;
    s32 i;
    s32 j;
    u32 k;
    f32 y;
    for (i = 0; i < o->f14; i++) {
        y = o->f50 + o->f58 - o->f54;
        for (j = 0; j < o->f10 + 2; j++) {
            func_003E7770(func_003BA208(o, i, j), o->f20[i], y + o->f54 * j - o->f78);
        }
        if (i == 0) {
            for (k = 0; k < o->f9C; k++) {
                func_003E7770(func_003BA228((s32)o, k), o->f5C, y + (f32)(k - 1) * o->f54 + o->f70);
            }
        }
    }
}
/* localdecomp:end func_003BAB48 */

/* localdecomp:start func_003BACD8 */
extern void func_003A5748(s32, s32, s32);
extern void func_003BB948(s32);
typedef struct {
    u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[8]; s32 f1C; u8 p20[0x30];
    f32 f50; f32 f54; u8 p58[4]; f32 f5C; u8 p60[8]; f32 f68; u8 p6C[0xC]; f32 f78;
} S_3B5440;
typedef struct { u8 p[0x40]; s32 f40; } E_3B5440;
void func_003BACD8(void *arg0, s32 b) {
    S_3B5440 *o = arg0;
    f32 base = o->f50;
    f32 step = o->f54;
    f32 y;
    if (b & 0x1000) {
        s32 n, j, d;
        n = o->f4 + o->f8;
        j = n - 1;
        if (n > 0) {
            while (j > 0 && ((E_3B5440 *)func_003BA1E8(o, 0, j))->f40 == 4) j--;
            if (((E_3B5440 *)func_003BA1E8(o, 0, j))->f40 != 4) {
                d = n - j;
                if (d <= o->f8 + 1) {
                    o->f8 = j - o->f4;
                } else {
                    s32 t;
                    t = o->f4 + 1;
                    o->f4 = t - (d - o->f8);
                    o->f8 = -1;
                }
            }
        }
        ((s32 (*)(s32, s32, s32))func_003A5748)(3, 0, 0);
        if (o->f8 < 0) {
            o->f8 = 0;
            if (o->f4 - 1 >= 0) o->f1C = 2;
        }
    } else if (b & 0x4000) {
        s32 n, j, d;
        n = o->f4 + o->f8;
        j = n + 1;
        if (n < o->fC - 1) {
            while (j < o->fC - 1 && ((E_3B5440 *)func_003BA1E8(o, 0, j))->f40 == 4) j++;
            if (((E_3B5440 *)func_003BA1E8(o, 0, j))->f40 != 4) {
                d = j - n;
                if (d <= o->f10 - o->f8) {
                    o->f8 = j - o->f4;
                } else {
                    o->f8 = o->f10;
                    o->f4 = j - o->f10;
                }
            }
        }
        ((s32 (*)(s32, s32, s32))func_003A5748)(3, 0, 0);
        if (o->f10 - 1 < o->f8) {
            o->f8 = o->f10 - 1;
            {
                s32 t = o->f4 + 1;
                if (!(o->fC - o->f10 < t)) o->f1C = 1;
            }
        }
    }
    y = base + (f32)o->f8 * step;
    func_003E7770(0x4F00B0, o->f5C, y - o->f68);
    func_003E7770(0x4F00AF, o->f5C, y - o->f78);
    func_003E7770(0x4F00B1, o->f5C, y + o->f68);
    func_003BB948(0x4F00AF);
}
/* localdecomp:end func_003BACD8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BAF60);

/* localdecomp:start func_003BAF68 */
void func_003BAF68(s32 *arg0, float float1, float float2, float float3, float float4, float float5) {
    float *floatPtr = (float *)arg0;
    
    floatPtr[24] = float2; // $f13 -> 0x60
    floatPtr[25] = float3; // $f14 -> 0x64
    floatPtr[26] = float4; // $f15 -> 0x68
    floatPtr[27] = float5; // $f16 -> 0x6c
    floatPtr[23] = float1; // $f12 -> 0x5c
    
    arg0[30] = 0;          // $zero -> 0x78
}
/* localdecomp:end func_003BAF68 */

/* localdecomp:start func_003BAF88 */
void func_003BAF88(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "swc1 $15, 0x88($4)\n"
        "swc1 $12, 0x7c($4)\n"
        "swc1 $13, 0x80($4)\n"
        :: "r"(a0)
    );
    *(f32 *)((u8 *)a0 + 0x84) = a3;
}
/* localdecomp:end func_003BAF88 */

typedef struct { u8 p0[0x40]; s32 f40; } Q_3B5708;
typedef struct { u8 p0[0x8C]; s32 f8C; s32 f90; s32 f94; s32 f98; } R_3B5708;
extern s32 func_003E8128();
/* localdecomp:start func_003BAFA0 */
extern s32 func_003BA208();
void func_003BAFA0(R_3B5708 *a, s32 b, s32 c, s32 d) {
    s32 r;
    switch (((Q_3B5708 *)func_003BA1E8(a, b, d))->f40) {
    case 0:
        r = func_003BA208(a, b, c);
        func_003E8128(r, a->f8C);
        break;
    case 1:
        r = func_003BA208(a, b, c);
        func_003E8128(r, a->f90);
        break;
    case 2:
        r = func_003BA208(a, b, c);
        func_003E8128(r, a->f94);
        break;
    case 3:
        r = func_003BA208(a, b, c);
        func_003E8128(r, a->f98);
        break;
    case 4:
        r = func_003BA208(a, b, c);
        func_003E8128(r, a->f90);
        break;
    }
}
/* localdecomp:end func_003BAFA0 */

/* localdecomp:start func_003BB090 */
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; s32 f10; s32 f14; } O_3B57F8;
extern s32 func_003E7BF0();
extern s32 func_003E8048();
extern void func_003BAB28(s32 *);
void func_003BB090(void *op) {
    O_3B57F8 *o = (O_3B57F8 *)op;
    s32 i;
    s32 a;
    s32 n;
    s32 j;
    s32 t;
    func_003BAB28((s32 *)o);
    for (i = 0; i < o->f14; i++) {
        {
            a = o->f4;
            t = a - 1;
            n = o->f10;
            if (t <= -1) t = 0;
            j = func_003BA208(o, i, 0);
            func_003E8048(j, func_003BA1E8(o, i, t));
            func_003BAFA0(o, i, 0, t);
            if (a != 0) {
                func_003E7BF0(func_003BA208(o, i, 0), 1, 1);
            } else {
                func_003E7BF0(func_003BA208(o, i, 0), 1, 0);
            }
            j = 1;
            if (n > 0) {
                do {
                    if (a >= 0 && a < o->fC) {
                        func_003E7BF0(func_003BA208(o, i, j), 1, 1);
                        t = func_003BA208(o, i, j);
                        func_003E8048(t, func_003BA1E8(o, i, a));
                        func_003BAFA0(o, i, j, a);
                    } else {
                        func_003E7BF0(func_003BA208(o, i, j), 1, 0);
                    }
                    j++;
                    n--;
                    a++;
                } while (n > 0);
            }
            if (a != o->fC) {
                func_003E7BF0(func_003BA208(o, i, j), 1, 1);
                if (a >= o->fC) a--;
                t = func_003BA208(o, i, j);
                func_003E8048(t, func_003BA1E8(o, i, a));
                func_003BAFA0(o, i, j, a);
            } else {
                func_003E7BF0(func_003BA208(o, i, j), 1, 0);
            }
        }
    }
}
/* localdecomp:end func_003BB090 */

/* localdecomp:start func_003BB308 */
extern s32 func_003823D0(s32);
extern void func_003BB348(s32, s32, s32);
void func_003BB308(s32 a, s32 b, s32 c) {
    func_003BB348(func_003823D0(a), b, c);
}
/* localdecomp:end func_003BB308 */

extern s32 func_0038E928(f32, s32, s32);
extern f32 func_003C4440(f32, f32, f32);
extern f32 D_001D9698;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BB348);

extern s32 D_001D8BE8[];

/* localdecomp:start func_003BB468 */
extern s32 D_001D8BE8_003BB468;
void func_003BB468(void) {
    *(u8 *)&D_001D8BE8_003BB468 = 1;
}
/* localdecomp:end func_003BB468 */

/* localdecomp:start func_003BB478 */
extern u8 D_001D8BE8_003BB478;
s32 func_003BB478(void) {
    return D_001D8BE8_003BB478;
}
/* localdecomp:end func_003BB478 */

/* localdecomp:start func_003BB480 */
extern u8 D_001D8BE8_003BB480;
void func_003BB480(void) {
    D_001D8BE8_003BB480 = 0;
}
/* localdecomp:end func_003BB480 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BB488);
