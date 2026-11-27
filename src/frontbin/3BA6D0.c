#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BABB0(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BAF50();
/* --- end of declarations from other files --- */

/* declarations of 3B9BD0.c's earlier functions */
extern s32 func_003B9E50(void *, s32, s32);
extern s32 func_003B9E70(s32, s32);
extern void func_003BA6D0(void *);
extern void func_003BA790(void *);
extern void func_003BA920(void *, s32);
extern void func_003BACD8(void *);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003B9E30(void *p, s32 x, s32 y);
extern s32 func_003B9E50(void *p, s32 x, s32 y);
extern s32 func_003B9E70(s32 a0, s32 a1);

/* localdecomp:start func_003BA6D0 */
void func_003BA6D0(void *arg0)
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
/* localdecomp:end func_003BA6D0 */

/* localdecomp:start func_003BA770 */
void func_003BA770(s32 *p) {
    s32 c = p[3];
    if (p[1] >= c) {
        p[1] = c - 1;
    }
}
/* localdecomp:end func_003BA770 */

/* localdecomp:start func_003BA790 */
typedef struct {
    u8 p0[0x10]; s32 f10; s32 f14; u8 p18[8]; f32 f20[12];
    f32 f50; f32 f54; f32 f58; f32 f5C; u8 p60[0x10]; f32 f70; u8 p74[4]; f32 f78; u8 p7C[0x20]; u32 f9C;
} S_3B52B0;
void func_003BA790(void *arg0) {
    S_3B52B0 *o = arg0;
    s32 i;
    s32 j;
    u32 k;
    f32 y;
    for (i = 0; i < o->f14; i++) {
        y = o->f50 + o->f58 - o->f54;
        for (j = 0; j < o->f10 + 2; j++) {
            func_003E73B8(func_003B9E50(o, i, j), o->f20[i], y + o->f54 * j - o->f78);
        }
        if (i == 0) {
            for (k = 0; k < o->f9C; k++) {
                func_003E73B8(func_003B9E70((s32)o, k), o->f5C, y + (f32)(k - 1) * o->f54 + o->f70);
            }
        }
    }
}
/* localdecomp:end func_003BA790 */

/* localdecomp:start func_003BA920 */
extern void func_003A5348(s32, s32, s32);
extern void func_003BB590(s32);
typedef struct {
    u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[8]; s32 f1C; u8 p20[0x30];
    f32 f50; f32 f54; u8 p58[4]; f32 f5C; u8 p60[8]; f32 f68; u8 p6C[0xC]; f32 f78;
} S_3B5440;
typedef struct { u8 p[0x40]; s32 f40; } E_3B5440;
void func_003BA920(void *arg0, s32 b) {
    S_3B5440 *o = arg0;
    f32 base = o->f50;
    f32 step = o->f54;
    f32 y;
    if (b & 0x1000) {
        s32 n, j, d;
        n = o->f4 + o->f8;
        j = n - 1;
        if (n > 0) {
            while (j > 0 && ((E_3B5440 *)func_003B9E30(o, 0, j))->f40 == 4) j--;
            if (((E_3B5440 *)func_003B9E30(o, 0, j))->f40 != 4) {
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
        ((s32 (*)(s32, s32, s32))func_003A5348)(3, 0, 0);
        if (o->f8 < 0) {
            o->f8 = 0;
            if (o->f4 - 1 >= 0) o->f1C = 2;
        }
    } else if (b & 0x4000) {
        s32 n, j, d;
        n = o->f4 + o->f8;
        j = n + 1;
        if (n < o->fC - 1) {
            while (j < o->fC - 1 && ((E_3B5440 *)func_003B9E30(o, 0, j))->f40 == 4) j++;
            if (((E_3B5440 *)func_003B9E30(o, 0, j))->f40 != 4) {
                d = j - n;
                if (d <= o->f10 - o->f8) {
                    o->f8 = j - o->f4;
                } else {
                    o->f8 = o->f10;
                    o->f4 = j - o->f10;
                }
            }
        }
        ((s32 (*)(s32, s32, s32))func_003A5348)(3, 0, 0);
        if (o->f10 - 1 < o->f8) {
            o->f8 = o->f10 - 1;
            {
                s32 t = o->f4 + 1;
                if (!(o->fC - o->f10 < t)) o->f1C = 1;
            }
        }
    }
    y = base + (f32)o->f8 * step;
    func_003E73B8(0x4F00B0, o->f5C, y - o->f68);
    func_003E73B8(0x4F00AF, o->f5C, y - o->f78);
    func_003E73B8(0x4F00B1, o->f5C, y + o->f68);
    func_003BB590(0x4F00AF);
}
/* localdecomp:end func_003BA920 */

LINKER_REMNANT("asm/remnants", func_003BABA8);

/* localdecomp:start func_003BABB0 */
void func_003BABB0(s32 *arg0, float float1, float float2, float float3, float float4, float float5) {
    float *floatPtr = (float *)arg0;
    
    floatPtr[24] = float2; // $f13 -> 0x60
    floatPtr[25] = float3; // $f14 -> 0x64
    floatPtr[26] = float4; // $f15 -> 0x68
    floatPtr[27] = float5; // $f16 -> 0x6c
    floatPtr[23] = float1; // $f12 -> 0x5c
    
    arg0[30] = 0;          // $zero -> 0x78
}
/* localdecomp:end func_003BABB0 */

/* localdecomp:start func_003BABD0 */
void func_003BABD0(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "swc1 $15, 0x88($4)\n"
        "swc1 $12, 0x7c($4)\n"
        "swc1 $13, 0x80($4)\n"
        :: "r"(a0)
    );
    *(f32 *)((u8 *)a0 + 0x84) = a3;
}
/* localdecomp:end func_003BABD0 */

typedef struct { u8 p0[0x40]; s32 f40; } Q_3B5708;
typedef struct { u8 p0[0x8C]; s32 f8C; s32 f90; s32 f94; s32 f98; } R_3B5708;
extern s32 func_003E7D70();
/* localdecomp:start func_003BABE8 */
extern s32 func_003B9E50();
void func_003BABE8(R_3B5708 *a, s32 b, s32 c, s32 d) {
    s32 r;
    switch (((Q_3B5708 *)func_003B9E30(a, b, d))->f40) {
    case 0:
        r = func_003B9E50(a, b, c);
        func_003E7D70(r, a->f8C);
        break;
    case 1:
        r = func_003B9E50(a, b, c);
        func_003E7D70(r, a->f90);
        break;
    case 2:
        r = func_003B9E50(a, b, c);
        func_003E7D70(r, a->f94);
        break;
    case 3:
        r = func_003B9E50(a, b, c);
        func_003E7D70(r, a->f98);
        break;
    case 4:
        r = func_003B9E50(a, b, c);
        func_003E7D70(r, a->f90);
        break;
    }
}
/* localdecomp:end func_003BABE8 */

/* localdecomp:start func_003BACD8 */
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; s32 f10; s32 f14; } O_3B57F8;
extern s32 func_003E7838();
extern s32 func_003E7C90();
extern void func_003BA770(s32 *);
void func_003BACD8(void *op) {
    O_3B57F8 *o = (O_3B57F8 *)op;
    s32 i;
    s32 a;
    s32 n;
    s32 j;
    s32 t;
    func_003BA770((s32 *)o);
    for (i = 0; i < o->f14; i++) {
        {
            a = o->f4;
            t = a - 1;
            n = o->f10;
            if (t <= -1) t = 0;
            j = func_003B9E50(o, i, 0);
            func_003E7C90(j, func_003B9E30(o, i, t));
            func_003BABE8(o, i, 0, t);
            if (a != 0) {
                func_003E7838(func_003B9E50(o, i, 0), 1, 1);
            } else {
                func_003E7838(func_003B9E50(o, i, 0), 1, 0);
            }
            j = 1;
            if (n > 0) {
                do {
                    if (a >= 0 && a < o->fC) {
                        func_003E7838(func_003B9E50(o, i, j), 1, 1);
                        t = func_003B9E50(o, i, j);
                        func_003E7C90(t, func_003B9E30(o, i, a));
                        func_003BABE8(o, i, j, a);
                    } else {
                        func_003E7838(func_003B9E50(o, i, j), 1, 0);
                    }
                    j++;
                    n--;
                    a++;
                } while (n > 0);
            }
            if (a != o->fC) {
                func_003E7838(func_003B9E50(o, i, j), 1, 1);
                if (a >= o->fC) a--;
                t = func_003B9E50(o, i, j);
                func_003E7C90(t, func_003B9E30(o, i, a));
                func_003BABE8(o, i, j, a);
            } else {
                func_003E7838(func_003B9E50(o, i, j), 1, 0);
            }
        }
    }
}
/* localdecomp:end func_003BACD8 */

/* localdecomp:start func_003BAF50 */
extern s32 func_00381FF0(s32);
extern void func_003BAF90(s32, s32, s32);
void func_003BAF50(s32 a, s32 b, s32 c) {
    func_003BAF90(func_00381FF0(a), b, c);
}
/* localdecomp:end func_003BAF50 */
