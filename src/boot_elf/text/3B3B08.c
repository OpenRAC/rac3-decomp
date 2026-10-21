#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A0B60(u8 *, u32);
extern void func_003B3CC8(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0B60(u8 *, u32);
extern s32 *func_003B4678();
extern void *func_003B46B0();
extern s32 *func_003B4738();
extern s32 *func_003B4768();
extern void func_003B3D90(void);
/* --- end of declarations from other files --- */

/* declarations of 3B3068.c's earlier functions (tools/port_from_us.py) */
extern void *func_003E6FC0();
extern void func_003E6DB0(void *);
extern u8 D_001DA938[];
extern u8 D_001D8880;
extern void func_003E86B0();
extern void *func_003E6FC0();
extern void func_003E6E18();
extern s32 func_003E68D0();
extern s32 func_003E72D0();
extern u8 D_001DA938[];
extern void *func_003E6FC0();
extern void func_003E6E50();
extern u8 D_001DA938[];
extern void *func_003E6FC0();
extern void func_003E6EE0(void *);
extern void func_003AA060();
extern void func_003E71C8_003B3510();
extern void func_003E6F70();
extern void *func_003E6FC0();
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern u8 D_001D8881;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003ADBB0;
extern S_003ADBB0 D_001DA938_003B3510;
extern s32 D_001D8888;
extern s32 D_001D888C;
extern s32 D_001D8888;
extern s32 D_001D888C;
extern void *D_001D8890;
extern void *D_001D8890;
extern void func_003B3610(void *, s32);
typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;
extern S_003ADCB0 D_00142430;
extern u8 D_001D4BE0;
extern u8 D_001D4BE0_b_003ADCB0;
extern void func_0012BE28();
extern void func_0013AD58();
extern void func_0039E9C0();
extern s32 D_001D888C;
extern void (*D_001DA100)();
extern void func_003A1398(s32, s32);
extern s32 D_001D888C;
extern s8 D_001D9FA0[];
extern s32 D_001D888C;
extern void func_0039C0E8();
extern void func_003B35E8();
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern s32 D_001D888C;
extern void func_0039C170();
extern void func_003B35E8();
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern void func_0039C0E8();
extern void func_003B4218(void);
extern void func_0013D3C0(s32);
extern s32 D_001D888C;
extern s32 D_001D8894;
extern s32 D_001D4CE8;
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003AE098;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern void func_003A43E0(void);
extern void func_0013BFE0(s32);
extern void func_003A9308(void);
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003AE120;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern void func_003A43E0(void);
extern s32 func_003A2B50(s32);
extern void func_0013BFE0(s32);
extern void func_003A9308(void);

/* localdecomp:start func_003B3B08 */
extern void func_0039C1A0();
extern void func_003B39C8();
extern void func_003B39F8();
extern s32 D_001D888C;
void func_003B3B08(void)
{
  s32 (*new_var)();
  s32 *new_var2;
  s32 temp_3;
  temp_3 = D_001D888C;
  new_var2 = &D_001D888C;
  switch (*new_var2)
  {
    case 0:
      new_var = &func_003B39C8;
      func_0039C1A0(new_var, 0, &func_003B39F8);

    case 1:
      func_003A12C0(4, 1, 1, 0, 0);
 do { } while (0);
      temp_3 = *new_var2;
      temp_3 = (s32) (temp_3 + 1);
      D_001D888C = temp_3;
      return;

    case 2:
      func_003B3D90();
      break;

  }

}
/* localdecomp:end func_003B3B08 */

/* PAL draft of func_003B3BA0 (from the US draft of rac3-uya-decomp func_003B3A00, commit 13cf5c5),
   names moved to PAL addresses where known. The US call target func_003B3BF8 is func_003B3D98 in
   PAL (src/boot_elf/text/3B3B08.c has INCLUDE_ASM for it). */


/* localdecomp:start func_003B3BA0 */
extern s32 D_001D888C;
extern s32 D_001D8898;
extern void func_0039C1A0();
extern void func_003B39C8();
extern void func_003B3A80();
extern void func_003B3D98(void);
extern void func_003B4218(void);
extern void func_003B3D90(void);
void func_003B3BA0(void) {
    switch (D_001D888C) {
    case 0:
        func_0039C1A0(func_003B39C8, 0, func_003B3A80);
        func_003B3D98();
        D_001D8898 = 30;
        D_001D888C++;
        break;
    case 1:
        func_003B3D98();
        { s32 t = D_001D8898; if (t > 0) { t--; D_001D8898 = t; } D_001D8898 = t; if (t == 0) func_003B4218(); }
        break;
    case 2:
        func_003B3D90();
        break;
    }
}
/* localdecomp:end func_003B3BA0 */

/* localdecomp:start func_003B3C60 */
extern s32 D_001D888C;
extern void func_003B3D90(void);
void func_003B3C60(void) {
    switch (D_001D888C) {
    case 0: D_001D888C = 1; break;
    case 1: D_001D888C = 2; break;
    case 2: func_003B3D90(); break;
    }
}
/* localdecomp:end func_003B3C60 */

/* localdecomp:start func_003B3CC8 */
__asm__(".extern D_001D8888, 4");
extern s32 D_001D8888;
extern void func_003B3858(void);
extern void func_003B37C8(void);
extern void func_003B3B08(void);
extern void func_003B38E8(void);
extern void func_003B3BA0_003B3CC8(void);
extern void func_003B3C60(void);
extern void func_003B3730(void);
extern void func_003B3690(void);
extern void func_003A1398(s32, s32);
void func_003B3CC8(void) {
    switch (D_001D8888) {
    case 1:
        func_003B3858();
        break;
    case 2:
        func_003B37C8();
        break;
    case 3:
        func_003B3B08();
        break;
    case 7:
        func_003B38E8();
        break;
    case 8:
        func_003B3BA0_003B3CC8();
        break;
    case 5:
        func_003B3C60();
        break;
    case 4:
        func_003B3730();
        break;
    case 6:
        func_003B3690();
        break;
    case 0:
    default:
        func_003A1398(0, 0);
        break;
    }
}
/* localdecomp:end func_003B3CC8 */

/* localdecomp:start func_003B3D90 */
extern s32 D_001D8888;
void func_003B3D90(void) {
    D_001D8888 = 0;
}
/* localdecomp:end func_003B3D90 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B3D98);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C690);

extern s32 D_001D4CE8_003B3BF8;
extern u8 D_001D9FA0_003B3BF8;
extern u8 D_001D5BDC_003B3BF8;
extern u8 D_001D5BDD_003B3BF8;
extern u8 D_001D88A0[];
extern u8 D_001D88A8[];
extern s32 func_003823D0();
extern void func_11B2E8();
extern void func_0038EBC8_003B3BF8(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
typedef struct { u8 pad0[8]; s32 f8; u8 pad0c[4]; s32 f10; } S_142430_003AE8A8;
extern s32 D_001D4CE8;
extern F_003B2F50 D_001D4CEC;
extern s32 D_001D888C;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern u8 D_001D9FA0_003B3BF8;
extern P_003B2F50 *D_001D52FC;
extern S_003ADCB0 D_00142430;
extern s32 func_0039C050(s32, s32);
extern void func_0039C6E0(void);
extern void func_003A9308(void);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B4218);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C710);

/* localdecomp:start func_003B4610 */
void func_003B4610(void *p, s32 a) {
    void *q = *(void **)((u8 *)p + 0x4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)q + 0x1C))(p, a, 0);
}
/* localdecomp:end func_003B4610 */

/* localdecomp:start func_003B4638 */
extern s32 func_00396D48(s32, s32);
s32 func_003B4638(u8 *p, s32 a, s32 b) {
    s32 r = func_00396D48(a, b);
    *(s32 *)(p + 8) = r;
    return r != 0;
}
/* localdecomp:end func_003B4638 */

/* localdecomp:start func_003B4670 */
s32 func_003B4670(void *p) {
    return *(s32 *)((u8 *)p + 0x8);
}
/* localdecomp:end func_003B4670 */

extern s32 D_001DA114;
extern s32 D_001DA108;
extern u8 *D_001DA10C[];
extern s32 D_001DA110[];
extern u8 D_001D8918[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B4678);

/* localdecomp:start func_003B46B0 */
extern void **func_003B47F0();
extern s32 D_001DA118;
extern u8 D_00240A20[];
void *func_003B46B0(s32 arg0) {
    s32 i; u8 *p;
    if (D_001DA118 == 0) {
        p = D_00240A20;
        i = 3;
        do { func_003B47F0(p); i--; __asm__ volatile("nop"); p += 0x20; } while (i != -1);
        D_001DA118 = 1;
    }
    return (arg0 << 5) + D_00240A20;
}
/* localdecomp:end func_003B46B0 */

extern s32 D_001DA12C;
extern s32 D_001DA120;
extern u8 *D_001DA124[];
extern u8 D_001D88B8[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B4738);

/* localdecomp:start func_003B4768 */
typedef struct { u8 b[0x14]; } E_3AEDF8;
extern E_3AEDF8 D_00240AA0[];
extern s32 D_001DA130;
extern void **func_003B4A10(void **);
s32 *func_003B4768(s32 idx) {
    s32 i;
    E_3AEDF8 *p;
    if (D_001DA130 == 0) {
        p = D_00240AA0;
        i = 3;
        do {
            func_003B4A10((void **)p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA130 = 1;
    }
    return (s32 *)&D_00240AA0[idx];
}
/* localdecomp:end func_003B4768 */

extern u8 D_001D88F8[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B47F0);

/* localdecomp:start func_003B4828 */
s32 func_003B4828(s32 *p) {
    *p = 8;
    return 1;
}
/* localdecomp:end func_003B4828 */

/* localdecomp:start func_003B4838 */
extern s32 func_003A2998(s32, s32, s32);
extern s16 D_001CCFD4[];
s32 func_003B4838(void *arg0, s32 arg1)
{
  s32 temp_3;
  s32 temp_4;
  s32 temp_6;
  u8 *new_var2;
  char var_7;
  int new_var;
  void *temp_6_2;
  temp_6 = *((s32 *) (((u8 *) arg0) + 0x14));
  var_7 = 0;
  if (temp_6 != 0)
  {
    temp_4 = *((s32 *) (((u8 *) arg0) + 0xC));
    if (temp_4 != 0)
    {
      temp_3 = *((s32 *) (((u8 *) arg0) + 0));
      if (((temp_3 ^ 4) != 0) && ((temp_3 ^ 8) != 0))
      {
        if (D_001CCFD4[0] == 0)
        {
          new_var = 8;
 do { temp_6_2 = (arg1 * new_var) + temp_6; if ((*((s32 *) (((u8 *) temp_6_2) + 4))) > 0) { new_var2 = (u8 *) arg0; *((s32 *) (new_var2 + 0x1C)) = arg1; ((s32 (*)(s32, s32, s32, s32))func_003A2998)(temp_4, (*((s32 *) (((u8 *) temp_6_2) + 0))) + (*((s32 *) (((u8 *) arg0) + 0x18))), *((s32 *) (((u8 *) temp_6_2) + 4)), 0); var_7 = 1; *((s32 *) (((u8 *) arg0) + 0)) = 4; } } while (0);
        }
        else
        {
          *((s32 *) (((u8 *) arg0) + 0x1C)) = arg1;
          *((s32 *) (((u8 *) arg0) + 0)) = 0x10;
          var_7 = 1;
        }
      }
    }
  }
  return var_7;
}
/* localdecomp:end func_003B4838 */

typedef struct { s32 type; s8 pad4[8]; s32 fC; s32 f10; s32 f14; s32 f18; } S_3AEF70;
/* localdecomp:start func_003B48E0 */
s32 func_003B48E0(S_3AEF70 *a, s32 b, s32 c, s32 d, s32 e) {
    s32 result = 0;
    s32 t = a->type;
    if ((t ^ 2) == 0 || (t ^ 1) == 0 || (t ^ 8) == 0) {
        a->fC = b;
        a->f10 = c;
        a->f18 = d;
        a->f14 = e;
        result = 1;
    }
    return result;
}
/* localdecomp:end func_003B48E0 */

/* localdecomp:start func_003B4920 */
s32 func_003B4920(s32 *arg0) {
    s32 val = arg0[4]; // offset 0x10 (4 * 4 bytes)
    
    if (val != 0) {
        return val;
    }
    
    return arg0[3]; // offset 0x0C (3 * 4 bytes)
}
/* localdecomp:end func_003B4920 */

/* localdecomp:start func_003B4940 */
s32 func_003B4940(s32 *p) {
    s32 s = p[0];
    if ((s ^ 0x10) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 *e = (s32 *)(p[7] * 8 + p[5]);
            func_003A2998(p[3], e[0] + p[6], e[1]);
            p[0] = 4;
        }
    } else if ((s ^ 8) == 0) {
        if (D_001CCFD4[0] == 0) {
            p[0] = 1;
        }
    } else if ((s ^ 4) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 v = 2;
            if (p[4] != 0) {
                func_003A0B60((u8 *)p[3], p[4]);
            }
            p[0] = v;
        }
    }
    return 1;
}
/* localdecomp:end func_003B4940 */

extern u8 D_001D88D8[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B4A10);

/* localdecomp:start func_003B4A38 */
s32 func_003B4A38(void) {
    return 1;
}
/* localdecomp:end func_003B4A38 */

/* localdecomp:start func_003B4A40 */
s32 func_003B4A40(s32 *p) {
    s32 v = 1;
    if (p[3] != 0) {
        if (p[4] != 0) {
            func_003A0B60((u8 *)p[3], p[4]);
        }
        v = 2;
    }
    p[0] = v;
    return 1;
}
/* localdecomp:end func_003B4A40 */

/* localdecomp:start func_003B4A90 */
s32 func_003B4A90(s32 *arg0) {
    if (arg0[4] != 0) {
        return arg0[4];
    }
    return arg0[3];
}
/* localdecomp:end func_003B4A90 */

/* localdecomp:start func_003B4AB0 */
s32 func_003B4AB0(void) {
    return 1;
}
/* localdecomp:end func_003B4AB0 */

/* localdecomp:start func_003B4AB8 */
s32 func_003B4AB8(void) {
    return 2;
}
/* localdecomp:end func_003B4AB8 */

/* localdecomp:start func_003B4AC0 */
s32 func_003B4AC0(void) {
    return 0;
}
/* localdecomp:end func_003B4AC0 */

/* localdecomp:start func_003B4AC8 */
s32 func_003B4AC8(void) {
    return 1;
}
/* localdecomp:end func_003B4AC8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B4AD0);

/* localdecomp:start func_003B4AD8 */
s32 func_003B4AD8(void) {
    return 0;
}
/* localdecomp:end func_003B4AD8 */

/* localdecomp:start func_003B4AE0 */
s32 func_003B4AE0(void) {
    return 1;
}
/* localdecomp:end func_003B4AE0 */

/* localdecomp:start func_003B4AE8 */
s32 func_003B4AE8(void) {
    return 0;
}
/* localdecomp:end func_003B4AE8 */

/* localdecomp:start func_003B4AF0 */
s32 func_003B4AF0(void) {
    return 0;
}
/* localdecomp:end func_003B4AF0 */

/* localdecomp:start func_003B4AF8 */
s32 func_003B4AF8(void) {
    return 0;
}
/* localdecomp:end func_003B4AF8 */

/* localdecomp:start func_003B4B00 */
s32 func_003B4B00(void) {
    return 1;
}
/* localdecomp:end func_003B4B00 */

/* localdecomp:start func_003B4B08 */
extern void func_00398128(s32, s32);
 
void func_003B4B08(void) {
    func_00398128(0, 0);
}
/* localdecomp:end func_003B4B08 */

/* localdecomp:start func_003B4B28 */
extern void func_003BBB68(s32);
extern void func_003B35E0(void *);
extern void func_003B68C0(s32);
extern s32 func_003B8338(void);
extern s32 func_003E8780();
extern void *func_003B5388();
extern void func_003E73B0(void *p);
extern u8 D_00240AF0[];
void func_003B4B28(void) {
    func_003BBB68(1);
    func_003B35E0(D_00240AF0);
    func_003B68C0(2);
    func_003E8780(func_003B8338());
    func_003E73B0(func_003B5388());
}
/* localdecomp:end func_003B4B28 */

/* localdecomp:start func_003B4B78 */
extern void func_003BBB68(s32);
extern void func_003B68C0(s32);
extern s32 func_003B8338(void);
extern s32 func_003E8780();
extern void *func_003B5388();
extern void func_003E73B0(void *p);
void func_003B4B78(void) {
    func_003B68C0(1);
    func_003BBB68(1);
    func_003E8780(func_003B8338());
    func_003E73B0(func_003B5388());
}
/* localdecomp:end func_003B4B78 */

/* localdecomp:start func_003B4BC0 */
extern s32 func_003B5580(void);
extern s32 func_003E8780();
extern void *func_003B5388();   /* no prototype: func_003B53E0 passes an arg */
extern void func_003E73B0(void *p);
 
void func_003B4BC0(void) {
    func_003E8780(func_003B5580());
    func_003E73B0(func_003B5388());
}
/* localdecomp:end func_003B4BC0 */

/* localdecomp:start func_003B4BF8 */
extern u8 D_00227400[];
extern s32 func_00392F00();
extern s32 func_00393058(void *);
void func_003B4BF8(void) {
    func_00392F00(D_00227400, 0x2B);
    func_00393058(D_00227400);
}
/* localdecomp:end func_003B4BF8 */

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } E_3AF2C0;
extern f32 D_001D894C;
extern f32 D_001D8940;
extern f32 D_001D8944;
extern f32 D_001D8950;
extern f32 D_001D8958;
extern f32 D_001D8954;
extern f32 D_001D895C;
extern E_3AF2C0 D_00337640_003B4C30[];
extern s32 func_003E92A8(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E94F0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8EA0(s32, s32, s32, s32, s32, s32);
extern s32 func_003E9710(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E91F0(s32, s32, s32);
extern s32 func_003E8C50(s32, f32, f32);
extern s32 func_003E8D10(s32, s32);
extern s32 func_003E8DC0(s32, s32, s32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003823D0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B4C30);

typedef struct { s32 x0; s32 x4; u8 b8; u8 p9[3]; void (*fnC)(void); } E_3B4ED8;
extern f32 D_001D8960[2];
extern f32 D_001D8970;
extern s32 D_001D8948;
extern s32 D_001DA13C;
extern s32 D_001DA144;
extern f32 D_001DA138;
extern f32 D_001DA140;
extern f32 D_001D8944;
extern f32 D_001D8940;
extern f32 D_001D8974;
extern f32 D_001D8978;
extern f32 D_001D8998[2];
extern f32 D_001D8980[2];
extern u8 *D_001D52FC_003B5088;
extern E_3B4ED8 D_00337640[];
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E8128(s32, s32);
extern void func_003A5748();
extern s32 func_003BB478();
extern void func_003BB480();
extern void func_003E73B0(void *p);
extern void func_003BB988();
extern void func_003BB948(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B5088);

/* localdecomp:start func_003B5350 */
extern s32 func_003E8960();
 
void func_003B5350(void) {
    func_003E8960(0x10);
    func_003E8960(0x11);
}
/* localdecomp:end func_003B5350 */

/* localdecomp:start func_003B5378 */
s32 func_003B5378(void) {
}
/* localdecomp:end func_003B5378 */

/* localdecomp:start func_003B5380 */
s32 func_003B5380(void) {
}
/* localdecomp:end func_003B5380 */

/* localdecomp:start func_003B5388 */
extern s32 func_003E7358(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA160;
extern s32 D_001DA148[2];
extern void func_003B4C30();
extern void func_003B5350(void);
extern void func_003B5088();
extern s32 func_003B5378(void);
extern s32 func_003B5380(void);
void *func_003B5388() {
    if (D_001DA160 == 0) {
        func_003E7358(D_001DA148, (s32)func_003B4C30, (s32)func_003B5350, (s32)func_003B5088, (s32)func_003B5378, (s32)func_003B5380);
        D_001DA160 = 1;
    }
    return D_001DA148;
}
/* localdecomp:end func_003B5388 */

/* localdecomp:start func_003B53E0 */
void func_003B53E0(s32 arg0) {
    func_003B5388(arg0);
}
/* localdecomp:end func_003B53E0 */

/* localdecomp:start func_003B5400 */
extern u8 D_00337690[];
 
void *func_003B5400(s32 i) {
    return D_00337690 + i * 0x9000;
}
/* localdecomp:end func_003B5400 */

/* localdecomp:start func_003B5418 */
typedef struct { void *f0; void *f4; void *(*f8)(void *, void *); void (*fC)(void *, void *); } VT_3AFAA8;
typedef struct { VT_3AFAA8 *vt; } O_3AFAA8;
typedef struct { void *f0; void *f4; void (*f8)(void *, s32); } VT2_3AFAA8;
typedef struct { s32 f0; s32 f4; VT2_3AFAA8 *vt; } P_3AFAA8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3AFAA8;
extern u8 D_001DA938[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern void func_003E7758(s32);
extern s32 func_003E7760();
extern s32 func_003E5CB0();
extern s32 func_003E7078();
extern s32 func_003F2740(s32, s32);
extern s32 func_003EE310();
extern void func_003E6700();
s32 func_003B5418(s32 a0) {
    S_3AFAA8 *q;
    void *x;
    void *s;
    void *w;
    void *e;
    P_3AFAA8 *p;
    O_3AFAA8 *o;
    s32 r = 0;
    x = D_001DA938;
    if (((S_3AFAA8 *)x)->f4 == 0) x = func_003E6FC0();
    s = (void *)func_003E71A0(x);
    func_003E7758(0x30);
    w = (void *)func_003E7760();
    if (s != 0) {
        if (func_003E5CB0(s, a0) == 0) {
            q = (S_3AFAA8 *)D_001DA938;
            if (q->f4 != 0) x = q; else x = func_003E6FC0(q);
            o = (O_3AFAA8 *)func_003E7078(x, 1);
            e = o->vt->f8(o, w);
            if (e != 0) {
                p = (P_3AFAA8 *)func_003EE310(func_003F2740(0x30, (s32)e));
                r = ((s32 (*)())func_003E6700)(s, p, a0) != 0;
                if (r == 0) {
                    p->vt->f8(p, 2);
                    q = (S_3AFAA8 *)D_001DA938;
                    if (q->f4 != 0) x = q; else x = func_003E6FC0(q);
                    o = (O_3AFAA8 *)func_003E7078(x, 1);
                    o->vt->fC(o, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003B5418 */

/* localdecomp:start func_003B5580 */
extern s32 func_003E7358(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA180;
extern s32 D_001DA168[2];
extern void func_003B55D8();
extern void func_003B5B80(void);
extern void func_003B5890();
extern void func_003B5BC8(void);
extern void func_003B5BE8(void);
s32 func_003B5580(void) {
    if (D_001DA180 == 0) {
        func_003E7358(D_001DA168, (s32)func_003B55D8, (s32)func_003B5B80, (s32)func_003B5890, (s32)func_003B5BC8, (s32)func_003B5BE8);
        D_001DA180 = 1;
    }
    return (s32)D_001DA168;
}
/* localdecomp:end func_003B5580 */

extern s32 D_001D89BC;
extern s32 D_001D89E4;
extern u8 D_0037F880[];
extern f32 D_001D9698_003B55D8;
extern void func_003B5EF0();
extern void func_0038E530(s32);
extern s32 func_003823D0();
extern s32 func_0038E928(f32, s32, s32);
extern f32 func_003C4440(f32, f32, f32);
extern void func_003B9650(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E85A8(s32, f32, f32);
extern void func_003B5C10();
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern s32 func_003E7DD0(s32, s32);
extern s32 func_003E8AC8(s32, s32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E8B70(s32, s32, s32);
extern void func_003B6128();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B55D8);

typedef struct { u8 p[0x1C0]; u32 f1C0; u32 f1C4; } P_3AFF20;
extern s32 D_001D89E4;
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D89B0;
extern s32 D_001D89B4;
extern s32 D_001D89FC;
extern s32 D_001D5520_003B5890;
extern s32 D_001D5520_g_003AFF20;
extern P_3AFF20 *D_001D52FC_003B5890;
extern P_3AFF20 *D_001D52FC_g_003AFF20;
extern u8 D_0037F690[];
extern char D_001D89F0[];
extern s32 func_003B9B68(void);
extern s32 func_003B9A88(void);
extern s32 func_003B9AB8();
extern void func_003B9A90();
extern void func_003B67F0(void);
extern void func_003B9C48(void);
extern void func_003917E8(s32, s32, s32);
extern void func_003BA8B0(void *, s32);
extern void func_11B2E8();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B5890);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C790);

/* localdecomp:start func_003B5B80 */
extern s32 func_003E8960();
extern void func_003B5F48(void);
extern s32 func_003A2B50(s32);
extern void func_003B9C48(void);
void func_003B5B80(void) {
    func_003E8960(0x10);
    func_003E8960(0x11);
    func_003E8960(0x14);
    func_003B5F48();
    func_003A2B50(1);
    func_003B9C48();
}
/* localdecomp:end func_003B5B80 */

/* localdecomp:start func_003B5BC8 */
void func_003B5BC8(void) {
    func_00381C48();
}
/* localdecomp:end func_003B5BC8 */

/* localdecomp:start func_003B5BE8 */
extern s32 func_00381C50(void);
extern void func_003B9C58();
 
void func_003B5BE8(void) {
    func_00381C50();
    func_003B9C58();
}
/* localdecomp:end func_003B5BE8 */

typedef struct {
    s32 f0; s32 f4; s32 f8; s32 fC; f32 f10; f32 f14; f32 f18; f32 f1C;
    u32 f20; s32 f24; f32 f28; u32 f2C;
} E_3B02A0;
extern void func_003E9808();
extern s32 func_003E9110(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E92A8(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E94F0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9470(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9710(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E7A38(s32, f32);
extern s32 func_003E7948(s32, f32, f32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E91F0(s32, s32, s32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B5C10);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C7B0);

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_3B0580;
extern S_3B0580 D_00160C40[];
extern void *D_001D89D0;
extern void *D_001D89D4;
/* localdecomp:start func_003B5EF0 */
extern void *func_003B5400(s32);
void func_003B5EF0(void) {
    D_001D89D0 = func_003B5400(0);
    D_001D89D4 = func_003B5400(2);
    func_003B48E0(func_003B46B0(0), (s32)D_001D89D0, (s32)D_001D89D4, D_00160C40->f4954, (s32)D_00160C40->f6F30);
}
/* localdecomp:end func_003B5EF0 */

/* localdecomp:start func_003B5F48 */
extern void *func_003B46B0(s32);
 
void func_003B5F48(void) {
    void *o = func_003B46B0(0);
    ((void (*)(void *))(*(void ***)((u8 *)o + 0x4))[3])(o);
}
/* localdecomp:end func_003B5F48 */

/* localdecomp:start func_003B5F78 */
extern u8 D_0037F830_003B5F78[];
extern u8 D_0037F690_003B5F78[];
extern s32 D_001D89B8_003B5F78;
extern s32 D_001D89E4_003B5F78;
extern void func_003A5748();
extern s32 func_003823D0();
extern void func_0011B2E8();
extern s32 func_003B9AB8();
extern void func_003B9A90();
extern s32 func_003E8780();
extern void *func_003B5388();
extern s32 func_003B5580(void);
extern void func_003E73B0(void *p);
__asm__(".extern D_001D89B8_003B5F78, 4");
__asm__(".extern D_001D89E4_003B5F78, 4");
void func_003B5F78(s32 a0, s32 a1) {
    s32 t;
    s32 u;
    u8 *g;
    if (a1 & 0x40) {
        func_003A5748(4, 0, 0);
        g = D_0037F830_003B5F78;
        t = D_001D89B8_003B5F78 * 16;
        if (((s32 *)(D_0037F830_003B5F78 + t))[2] != 0) {
            ((void (*)(s32, u8 *))((s32 *)(g + t))[2])(t, g);
        }
    } else if (a1 & 8) {
        func_0011B2E8(D_0037F690_003B5F78, func_003823D0(0xB3B));
 u = func_003823D0(0x8DE);
 func_003B9AB8(1, u, func_003823D0(0x8DF), D_0037F690_003B5F78, 0);
        func_003B9A90(0x40, 0x10);
        D_001D89E4_003B5F78 = 5;
    }
    if (a1 & 0x10) {
        func_003A5748(4, 0, 0);
        func_003E8780(func_003B5388());
        func_003E73B0((void *)func_003B5580());
    }
}
/* localdecomp:end func_003B5F78 */

/* localdecomp:start func_003B6090 */
typedef struct { s32 a, b, c, d; } E_37B870;
extern E_37B870 D_0037F830[];
extern s32 D_001D89B8;
extern s32 D_001D89BC;
extern s32 D_001D8A00;
extern s32 *func_003B9F88(s32);
extern s32 func_003BA010(s32 *);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E7DD0(s32 arg0, s32 arg1);
void func_003B6090(void) {
    s32 v = func_003BA010(func_003B9F88(0));
    D_001D89B8 = v;
    if (v < 0) return;
    if (D_001D89BC != v) {
        if (D_001D89BC >= 0) D_001D8A00 = 30;
        else D_001D8A00 = 1;
    }
    if (D_001D8A00 != 0) {
        if (--D_001D8A00 == 0) {
            func_003E8200(0x1C0003, D_0037F830[D_001D89B8].d);
            func_003E7DD0(0x1C0003, 1);
        }
    }
    D_001D89BC = D_001D89B8;
}
/* localdecomp:end func_003B6090 */

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B07B8;
extern s32 D_001D89C0;
extern s32 D_001D89C4;
extern s32 D_001D89C8;
extern s32 D_001D89CC;
extern f32 D_001D89D8;
extern f32 D_001D89DC;
extern f32 D_001D89E0;
extern char D_001D8A08[];
extern s32 *func_003B9F88(s32);
extern s32 func_003BA020();
extern void func_003BAF68(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003BAF88(void *, f32, f32, f32, f32);
extern void func_003BA898(void *, s32, f32, f32, f32);
extern void func_003BA710();
extern s32 func_003BA1E8_003B6128(void *, s32, s32);
extern s32 func_003823D0();
extern void func_11B2E8();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B6128);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B63D0);

extern u8 D_0037F830_003B6220[];
extern s32 *func_003B9F88(s32);
extern u8 D_0037F790[];
extern u8 D_0037F810[1];
extern char D_001D8A08[];
extern char D_001D8A10[];
extern s32 D_00143950_b[];
extern s32 func_003823D0();
extern void func_11B2E8();
extern s32 func_003B6860();
extern void func_003E8048_003B6220();
extern void *func_003BA1E8_003B6220();

/* localdecomp:start func_003B6588 */
extern s32 D_00143950_b[];
extern void func_003877A0();
 
void func_003B6588(void) {
    u8 *b = (u8 *)D_00143950_b;
    b[0xAD] = b[0xAD] == 0;
    func_003877A0();
}
/* localdecomp:end func_003B6588 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B65B8);

extern s32 D_001D5520_003B6430;
extern s32 D_001D89B0;
extern s32 D_001D89E4;
extern u8 D_0037F690[];
extern s32 func_003823D0();
extern void func_11B2E8();
extern void func_003B67F0(void);
extern s32 func_003B9AB8();
extern void func_003B9A90();
extern s32 D_00143950_b[];
extern void func_003B6638(void);

/* localdecomp:start func_003B6608 */
extern u8 D_00143950[];
s32 func_003B6608(void) {
    u8 *p = &D_00143950[0];
    s32 v = p[6] == 0;
    p[6] = v;
    return v;
}
/* localdecomp:end func_003B6608 */

/* localdecomp:start func_003B6620 */
extern s32 D_00143950_b[];

s32 func_003B6620(void) {
    s32 inverted_val = !D_00143950_b[2];
    D_00143950_b[2] = inverted_val;
    return inverted_val;
}
/* localdecomp:end func_003B6620 */
