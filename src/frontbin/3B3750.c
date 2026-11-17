#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B39D8(void);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_003A0760(u8 *, u32);
extern void func_003B3910(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0760(u8 *, u32);
extern s32 *func_003B42C0();
extern s32 *func_003B4380();
typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;


/* localdecomp:start func_003B3750 */
extern void func_0039BDC0();
extern void func_003B3610();
extern void func_003B3640_003B3750();
extern s32 D_001D888C;
void func_003B3750(void)
{
  s32 (*new_var)();
  s32 *new_var2;
  s32 temp_3;
  temp_3 = D_001D888C;
  new_var2 = &D_001D888C;
  switch (*new_var2)
  {
    case 0:
      new_var = &func_003B3610;
      func_0039BDC0(new_var, 0, &func_003B3640_003B3750);

    case 1:
      func_003A0EC0(4, 1, 1, 0, 0);
 do { } while (0);
      temp_3 = *new_var2;
      temp_3 = (s32) (temp_3 + 1);
      D_001D888C = temp_3;
      return;

    case 2:
      func_003B39D8();
      break;

  }

}
/* localdecomp:end func_003B3750 */

/* localdecomp:start func_003B37E8 */
extern s32 D_001D888C;
extern s32 D_001D8898;
extern void func_0039BDC0();
extern void func_003B3610();
extern void func_003B36C8();
extern void func_003B39E0(void);
extern void func_003B3E60(void);
extern void func_003B39D8(void);
void func_003B37E8(void) {
    switch (D_001D888C) {
    case 0:
        func_0039BDC0(func_003B3610, 0, func_003B36C8);
        func_003B39E0();
        D_001D8898 = 30;
        D_001D888C++;
        break;
    case 1:
        func_003B39E0();
        { s32 t = D_001D8898; if (t > 0) { t--; D_001D8898 = t; } D_001D8898 = t; if (t == 0) func_003B3E60(); }
        break;
    case 2:
        func_003B39D8();
        break;
    }
}
/* localdecomp:end func_003B37E8 */

/* localdecomp:start func_003B38A8 */
extern s32 D_001D888C;
extern void func_003B39D8(void);
void func_003B38A8(void) {
    switch (D_001D888C) {
    case 0: D_001D888C = 1; break;
    case 1: D_001D888C = 2; break;
    case 2: func_003B39D8(); break;
    }
}
/* localdecomp:end func_003B38A8 */

/* localdecomp:start func_003B3910 */
__asm__(".extern D_001D8888, 4");
extern s32 D_001D8888;
extern void func_003B34A0(void);
extern void func_003B3410(void);
extern void func_003B3750(void);
extern void func_003B3530(void);
extern void func_003B37E8_003B3910(void);
extern void func_003B38A8(void);
extern void func_003B3378_003B3910(void);
extern void func_003B32D8_003B3910(void);
extern void func_003A0F98(s32, s32);
void func_003B3910(void) {
    switch (D_001D8888) {
    case 1:
        func_003B34A0();
        break;
    case 2:
        func_003B3410();
        break;
    case 3:
        func_003B3750();
        break;
    case 7:
        func_003B3530();
        break;
    case 8:
        func_003B37E8_003B3910();
        break;
    case 5:
        func_003B38A8();
        break;
    case 4:
        func_003B3378_003B3910();
        break;
    case 6:
        func_003B32D8_003B3910();
        break;
    case 0:
    default:
        func_003A0F98(0, 0);
        break;
    }
}
/* localdecomp:end func_003B3910 */

/* localdecomp:start func_003B39D8 */
extern s32 D_001D8888;
void func_003B39D8(void) {
    D_001D8888 = 0;
}
/* localdecomp:end func_003B39D8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B39E0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C660);

extern s32 D_001D4CE8_003AE438;
extern u8 D_001D9FA0_003AE438;
extern u8 D_001D5BDC_003AE438;
extern u8 D_001D5BDD_003AE438;
extern u8 D_001D88A0[];
extern u8 D_001D88A8[];
extern s32 func_00381FF0();
extern void func_11B2E8();
extern void func_0038E7E8_003AE438(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
typedef struct { u8 pad0[8]; s32 f8; u8 pad0c[4]; s32 f10; } S_142430_003AE8A8;
extern s32 D_001D4CE8;
extern F_003B2F50 D_001D4CEC;
extern s32 D_001D888C;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern u8 D_001D9FA0_003AE438;
extern P_003B2F50 *D_001D52FC;
extern S_003ADCB0 D_00142430;
extern s32 func_0039BC70(s32, s32);
extern void func_0039C300(void);
extern void func_003A8F50(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003B3E60);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C6E0);

/* localdecomp:start func_003B4258 */
void func_003B4258(void *p, s32 a) {
    void *q = *(void **)((u8 *)p + 0x4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)q + 0x1C))(p, a, 0);
}
/* localdecomp:end func_003B4258 */

/* localdecomp:start func_003B4280 */
extern s32 func_00396968(s32, s32);
s32 func_003B4280(u8 *p, s32 a, s32 b) {
    s32 r = func_00396968(a, b);
    *(s32 *)(p + 8) = r;
    return r != 0;
}
/* localdecomp:end func_003B4280 */

/* localdecomp:start func_003B42B8 */
s32 func_003B42B8(void *p) {
    return *(s32 *)((u8 *)p + 0x8);
}
/* localdecomp:end func_003B42B8 */

extern s32 D_001DA114;
extern s32 D_001DA108;
extern u8 *D_001DA10C[];
extern s32 D_001DA110[];
extern u8 D_001D8918[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B42C0);

/* localdecomp:start func_003B42F8 */
extern void **func_003B4438();
extern s32 D_001DA118;
extern u8 D_00240A20[];
void *func_003B42F8(s32 arg0) {
    s32 i; u8 *p;
    if (D_001DA118 == 0) {
        p = D_00240A20;
        i = 3;
        do { func_003B4438(p); i--; __asm__ volatile("nop"); p += 0x20; } while (i != -1);
        D_001DA118 = 1;
    }
    return (arg0 << 5) + D_00240A20;
}
/* localdecomp:end func_003B42F8 */

extern s32 D_001DA12C;
extern s32 D_001DA120;
extern u8 *D_001DA124[];
extern u8 D_001D88B8[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B4380);

/* localdecomp:start func_003B43B0 */
typedef struct { u8 b[0x14]; } E_3AEDF8;
extern E_3AEDF8 D_00240AA0[];
extern s32 D_001DA130;
extern void **func_003B4658(void **);
s32 *func_003B43B0(s32 idx) {
    s32 i;
    E_3AEDF8 *p;
    if (D_001DA130 == 0) {
        p = D_00240AA0;
        i = 3;
        do {
            func_003B4658((void **)p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA130 = 1;
    }
    return (s32 *)&D_00240AA0[idx];
}
/* localdecomp:end func_003B43B0 */

extern u8 D_001D88F8[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B4438);

/* localdecomp:start func_003B4470 */
s32 func_003B4470(s32 *p) {
    *p = 8;
    return 1;
}
/* localdecomp:end func_003B4470 */

/* localdecomp:start func_003B4480 */
extern s32 func_003A2598(s32, s32, s32);
extern s16 D_001CCFD4[];
s32 func_003B4480(void *arg0, s32 arg1)
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
 do { temp_6_2 = (arg1 * new_var) + temp_6; if ((*((s32 *) (((u8 *) temp_6_2) + 4))) > 0) { new_var2 = (u8 *) arg0; *((s32 *) (new_var2 + 0x1C)) = arg1; ((s32 (*)(s32, s32, s32, s32))func_003A2598)(temp_4, (*((s32 *) (((u8 *) temp_6_2) + 0))) + (*((s32 *) (((u8 *) arg0) + 0x18))), *((s32 *) (((u8 *) temp_6_2) + 4)), 0); var_7 = 1; *((s32 *) (((u8 *) arg0) + 0)) = 4; } } while (0);
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
/* localdecomp:end func_003B4480 */

typedef struct { s32 type; s8 pad4[8]; s32 fC; s32 f10; s32 f14; s32 f18; } S_3AEF70;
/* localdecomp:start func_003B4528 */
s32 func_003B4528(S_3AEF70 *a, s32 b, s32 c, s32 d, s32 e) {
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
/* localdecomp:end func_003B4528 */

/* localdecomp:start func_003B4568 */
s32 func_003B4568(s32 *arg0) {
    s32 val = arg0[4]; // offset 0x10 (4 * 4 bytes)
    
    if (val != 0) {
        return val;
    }
    
    return arg0[3]; // offset 0x0C (3 * 4 bytes)
}
/* localdecomp:end func_003B4568 */

/* localdecomp:start func_003B4588 */
s32 func_003B4588(s32 *p) {
    s32 s = p[0];
    if ((s ^ 0x10) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 *e = (s32 *)(p[7] * 8 + p[5]);
            func_003A2598(p[3], e[0] + p[6], e[1]);
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
                func_003A0760((u8 *)p[3], p[4]);
            }
            p[0] = v;
        }
    }
    return 1;
}
/* localdecomp:end func_003B4588 */

extern u8 D_001D88D8[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B4658);

/* localdecomp:start func_003B4680 */
s32 func_003B4680(void) {
    return 1;
}
/* localdecomp:end func_003B4680 */

/* localdecomp:start func_003B4688 */
s32 func_003B4688(s32 *p) {
    s32 v = 1;
    if (p[3] != 0) {
        if (p[4] != 0) {
            func_003A0760((u8 *)p[3], p[4]);
        }
        v = 2;
    }
    p[0] = v;
    return 1;
}
/* localdecomp:end func_003B4688 */

/* localdecomp:start func_003B46D8 */
s32 func_003B46D8(s32 *arg0) {
    if (arg0[4] != 0) {
        return arg0[4];
    }
    return arg0[3];
}
/* localdecomp:end func_003B46D8 */

/* localdecomp:start func_003B46F8 */
s32 func_003B46F8(void) {
    return 1;
}
/* localdecomp:end func_003B46F8 */

/* localdecomp:start func_003B4700 */
s32 func_003B4700(void) {
    return 2;
}
/* localdecomp:end func_003B4700 */

/* localdecomp:start func_003B4708 */
s32 func_003B4708(void) {
    return 0;
}
/* localdecomp:end func_003B4708 */

/* localdecomp:start func_003B4710 */
s32 func_003B4710(void) {
    return 1;
}
/* localdecomp:end func_003B4710 */

LINKER_REMNANT("asm/remnants", func_003B4718);

/* localdecomp:start func_003B4720 */
s32 func_003B4720(void) {
    return 0;
}
/* localdecomp:end func_003B4720 */

/* localdecomp:start func_003B4728 */
s32 func_003B4728(void) {
    return 1;
}
/* localdecomp:end func_003B4728 */

/* localdecomp:start func_003B4730 */
s32 func_003B4730(void) {
    return 0;
}
/* localdecomp:end func_003B4730 */

/* localdecomp:start func_003B4738 */
s32 func_003B4738(void) {
    return 0;
}
/* localdecomp:end func_003B4738 */

/* localdecomp:start func_003B4740 */
s32 func_003B4740(void) {
    return 0;
}
/* localdecomp:end func_003B4740 */

/* localdecomp:start func_003B4748 */
s32 func_003B4748(void) {
    return 1;
}
/* localdecomp:end func_003B4748 */

/* localdecomp:start func_003B4750 */
extern void func_00397D48(s32, s32);
 
void func_003B4750(void) {
    func_00397D48(0, 0);
}
/* localdecomp:end func_003B4750 */

/* localdecomp:start func_003B4770 */
extern void func_003BB7B0(s32);
extern void func_003B3228(void *);
extern void func_003B6508(s32);
extern s32 func_003B7F80(void);
extern s32 func_003E83C8();
extern void *func_003B4FD0();
extern void func_003E6FF8(void *p);
extern u8 D_00240AF0[];
void func_003B4770(void) {
    func_003BB7B0(1);
    func_003B3228(D_00240AF0);
    func_003B6508(2);
    func_003E83C8(func_003B7F80());
    func_003E6FF8(func_003B4FD0());
}
/* localdecomp:end func_003B4770 */

/* localdecomp:start func_003B47C0 */
extern void func_003BB7B0(s32);
extern void func_003B6508(s32);
extern s32 func_003B7F80(void);
extern s32 func_003E83C8();
extern void *func_003B4FD0();
extern void func_003E6FF8(void *p);
void func_003B47C0(void) {
    func_003B6508(1);
    func_003BB7B0(1);
    func_003E83C8(func_003B7F80());
    func_003E6FF8(func_003B4FD0());
}
/* localdecomp:end func_003B47C0 */

/* localdecomp:start func_003B4808 */
extern s32 func_003B51C8(void);
extern s32 func_003E83C8();
extern void *func_003B4FD0();   /* no prototype: func_003B5028 passes an arg */
extern void func_003E6FF8(void *p);
 
void func_003B4808(void) {
    func_003E83C8(func_003B51C8());
    func_003E6FF8(func_003B4FD0());
}
/* localdecomp:end func_003B4808 */

/* localdecomp:start func_003B4840 */
extern u8 D_00227400[];
extern s32 func_00392B20();
extern s32 func_00392C78(void *);
void func_003B4840(void) {
    func_00392B20(D_00227400, 0x2B);
    func_00392C78(D_00227400);
}
/* localdecomp:end func_003B4840 */

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } E_3AF2C0;
extern f32 D_001D894C;
extern f32 D_001D8940;
extern f32 D_001D8944;
extern f32 D_001D8950;
extern f32 D_001D8958;
extern f32 D_001D8954;
extern f32 D_001D895C;
extern E_3AF2C0 D_00337640_003B4878[];
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8E38(s32, s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E8958(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_00381FF0();
INCLUDE_ASM("asm/nonmatchings/text", func_003B4878);

typedef struct { s32 x0; s32 x4; u8 b8; u8 p9[3]; void (*fnC)(void); } E_3AF718;
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
extern u8 *D_001D52FC_003B4CD0;
extern E_3AF718 D_00337640[];
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7D70(s32, s32);
extern void func_003A5348();
extern s32 func_003BB0C0();
extern void func_003BB0C8();
extern void func_003E6FF8(void *p);
extern void func_003BB5D0();
extern void func_003BB590(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B4CD0);

/* localdecomp:start func_003B4F98 */
extern s32 func_003E85A8();
 
void func_003B4F98(void) {
    func_003E85A8(0x10);
    func_003E85A8(0x11);
}
/* localdecomp:end func_003B4F98 */

/* localdecomp:start func_003B4FC0 */
s32 func_003B4FC0(void) {
}
/* localdecomp:end func_003B4FC0 */

/* localdecomp:start func_003B4FC8 */
s32 func_003B4FC8(void) {
}
/* localdecomp:end func_003B4FC8 */

/* localdecomp:start func_003B4FD0 */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA160;
extern s32 D_001DA148[2];
extern void func_003B4878();
extern void func_003B4F98(void);
extern void func_003B4CD0();
extern s32 func_003B4FC0(void);
extern s32 func_003B4FC8(void);
void *func_003B4FD0() {
    if (D_001DA160 == 0) {
        func_003E6FA0(D_001DA148, (s32)func_003B4878, (s32)func_003B4F98, (s32)func_003B4CD0, (s32)func_003B4FC0, (s32)func_003B4FC8);
        D_001DA160 = 1;
    }
    return D_001DA148;
}
/* localdecomp:end func_003B4FD0 */

/* localdecomp:start func_003B5028 */
void func_003B5028(s32 arg0) {
    func_003B4FD0(arg0);
}
/* localdecomp:end func_003B5028 */

/* localdecomp:start func_003B5048 */
extern u8 D_00337690[];
 
void *func_003B5048(s32 i) {
    return D_00337690 + i * 0x9000;
}
/* localdecomp:end func_003B5048 */

/* localdecomp:start func_003B5060 */
typedef struct { void *f0; void *f4; void *(*f8)(void *, void *); void (*fC)(void *, void *); } VT_3AFAA8;
typedef struct { VT_3AFAA8 *vt; } O_3AFAA8;
typedef struct { void *f0; void *f4; void (*f8)(void *, s32); } VT2_3AFAA8;
typedef struct { s32 f0; s32 f4; VT2_3AFAA8 *vt; } P_3AFAA8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3AFAA8;
extern u8 D_001DA938[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
extern s32 func_003E58F8();
extern s32 func_003E6CC0();
extern s32 func_003F2388(s32, s32);
extern s32 func_003EDF58();
extern void func_003E6348();
s32 func_003B5060(s32 a0) {
    S_3AFAA8 *q;
    void *x;
    void *s;
    void *w;
    void *e;
    P_3AFAA8 *p;
    O_3AFAA8 *o;
    s32 r = 0;
    x = D_001DA938;
    if (((S_3AFAA8 *)x)->f4 == 0) x = func_003E6C08();
    s = (void *)func_003E6DE8(x);
    func_003E73A0(0x30);
    w = (void *)func_003E73A8();
    if (s != 0) {
        if (func_003E58F8(s, a0) == 0) {
            q = (S_3AFAA8 *)D_001DA938;
            if (q->f4 != 0) x = q; else x = func_003E6C08(q);
            o = (O_3AFAA8 *)func_003E6CC0(x, 1);
            e = o->vt->f8(o, w);
            if (e != 0) {
                p = (P_3AFAA8 *)func_003EDF58(func_003F2388(0x30, (s32)e));
                r = ((s32 (*)())func_003E6348)(s, p, a0) != 0;
                if (r == 0) {
                    p->vt->f8(p, 2);
                    q = (S_3AFAA8 *)D_001DA938;
                    if (q->f4 != 0) x = q; else x = func_003E6C08(q);
                    o = (O_3AFAA8 *)func_003E6CC0(x, 1);
                    o->vt->fC(o, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003B5060 */

/* localdecomp:start func_003B51C8 */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA180;
extern s32 D_001DA168[2];
extern void func_003B5220();
extern void func_003B57C8(void);
extern void func_003B54D8();
extern void func_003B5810(void);
extern void func_003B5830(void);
s32 func_003B51C8(void) {
    if (D_001DA180 == 0) {
        func_003E6FA0(D_001DA168, (s32)func_003B5220, (s32)func_003B57C8, (s32)func_003B54D8, (s32)func_003B5810, (s32)func_003B5830);
        D_001DA180 = 1;
    }
    return (s32)D_001DA168;
}
/* localdecomp:end func_003B51C8 */

extern s32 D_001D89BC;
extern s32 D_001D89E4;
extern u8 D_0037F880[];
extern f32 D_001D9698_003B5220;
extern void func_003B5B38();
extern void func_0038E150(s32);
extern s32 func_00381FF0();
extern s32 func_0038E548(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern void func_003B5858();
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern void func_003B5D70();
INCLUDE_ASM("asm/nonmatchings/text", func_003B5220);

typedef struct { u8 p[0x1C0]; u32 f1C0; u32 f1C4; } P_3AFF20;
extern s32 D_001D89E4;
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D89B0;
extern s32 D_001D89B4;
extern s32 D_001D89FC;
extern s32 D_001D5520_003B54D8;
extern s32 D_001D5520_g_003B54D8;
extern P_3AFF20 *D_001D52FC_003B54D8;
extern P_3AFF20 *D_001D52FC_g_003B54D8;
extern u8 D_0037F690[];
extern char D_001D89F0[];
extern s32 func_003B97B0(void);
extern s32 func_003B96D0(void);
extern s32 func_003B9700();
extern void func_003B96D8();
extern void func_003B6438(void);
extern void func_003B9890(void);
extern void func_00391408(s32, s32, s32);
extern void func_003BA4F8(void *, s32);
extern void func_11B2E8();
/* localdecomp:start func_003B54D8 */
extern s32 D_001D89E4;
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D89B0;
extern s32 D_001D89B4;
extern s32 D_001D89FC;
extern s32 D_001D5520_003B54D8 __attribute__((section(".data")));
extern s32 D_001D5520_g_003B54D8;
extern P_3AFF20 *D_001D52FC_003B54D8 __attribute__((section(".data")));
extern P_3AFF20 *D_001D52FC_g_003B54D8;
extern u8 D_0037F690[];
extern char D_001D89F0[];
extern s32 func_003B97B0(void);
extern s32 func_003B96D0(void);
extern s32 func_003B9700();
extern void func_003B96D8();
extern void func_003B6438(void);
extern void func_003B9890(void);
extern void func_00391408(s32, s32, s32);
extern void func_003BA4F8(void *, s32);
extern void func_003B5CD8(void);
extern void func_003B5BC0(s32, s32);
extern void func_11B2E8();
extern s32 *func_003B9BD0(s32);
extern void func_003B6018(void);
void func_003B54D8(s32 a0) {
    switch (D_001D89E4) {
    case 1:
        if (func_003B97B0() != 0) break;
        switch (func_003B96D0()) {
        case 1: {
            u8 *buf; char *fmt;
            s32 x, y, z;
            D_001D89EC = D_001D89B0;
            D_001D89E8 = D_001D89B4;
            buf = D_0037F690;
            fmt = D_001D89F0;
            x = func_00381FF0(0x511);
            y = func_00381FF0(0x512);
            z = func_00381FF0(0x513);
            func_11B2E8(buf, fmt, x, y, D_001D89EC, z);
            {
                s32 w = func_00381FF0(0x8E3);
                func_003B9700(0, w, func_00381FF0(0x8DF), buf, 0);
            }
            func_003B96D8(0x20, 0x10);
            D_001D89E4 = 2;
            break;
        }
        case 2:
            D_001D89E4 = 0;
            break;
        }
        break;
    case 2:
        D_001D5520_g_003B54D8 = D_001D5520_003B54D8 == 0;
        func_003B6438();
        D_001D89E4 = 3;
        break;
    case 3: {
        u8 *buf; char *fmt;
        s32 x, y, z;
        buf = D_0037F690;
        fmt = D_001D89F0;
        x = func_00381FF0(0x511);
        y = func_00381FF0(0x512);
        z = func_00381FF0(0x513);
        func_11B2E8(buf, fmt, x, y, D_001D89EC, z);
        if (func_003B97B0() == 0) {
            switch (func_003B96D0()) {
            case 1:
                D_001D89E4 = 0;
                break;
            case 2:
                D_001D89E4 = 4;
                break;
            }
        } else {
            if (--D_001D89E8 > 0) break;
            if (--D_001D89EC <= 0) {
                ((s32 (*)(void))func_003B9890)();
                D_001D89E4 = 4;
            }
            D_001D89E8 = D_001D89B4;
        }
        break;
    }
    case 4:
        D_001D5520_g_003B54D8 = D_001D5520_003B54D8 == 0;
        func_003B6438();
        D_001D89E4 = 0;
        break;
    case 5: {
        u32 bits;
        if (func_003B97B0() == 0) {
            D_001D89E4 = 0;
            break;
        }
        bits = D_001D52FC_g_003B54D8->f1C0;
        if (bits & 0xF000) {
            s32 dx, dy;
            u32 q;
            if (++D_001D89FC < 3) break;
            D_001D89FC = 0;
            if (bits & 0x8000) dx = -2;
            else dx = (bits & 0x2000) ? 2 : 0;
            q = D_001D52FC_003B54D8->f1C0;
            if (q & 0x1000) dy = -1;
            else if (q & 0x4000) dy = 1;
            else dy = 0;
            func_00391408(dx, dy, 1);
        }
        break;
    }
    case 0: {
        s32 b = D_001D52FC_003B54D8->f1C4;
        func_003BA4F8(func_003B9BD0(0), b);
        func_003B5CD8();
        func_003B5BC0(a0, b);
        func_003B6018();
        break;
    }
    }
}
/* localdecomp:end func_003B54D8 */

/* localdecomp:start func_003B57C8 */
extern s32 func_003E85A8();
extern void func_003B5B90(void);
extern s32 func_003A2750(s32);
extern void func_003B9890(void);
void func_003B57C8(void) {
    func_003E85A8(0x10);
    func_003E85A8(0x11);
    func_003E85A8(0x14);
    func_003B5B90();
    func_003A2750(1);
    func_003B9890();
}
/* localdecomp:end func_003B57C8 */

/* localdecomp:start func_003B5810 */
void func_003B5810(void) {
    func_00381D38();
}
/* localdecomp:end func_003B5810 */

/* localdecomp:start func_003B5830 */
extern s32 func_00381D40(void);
extern void func_003B98A0();
 
void func_003B5830(void) {
    func_00381D40();
    func_003B98A0();
}
/* localdecomp:end func_003B5830 */

typedef struct {
    s32 f0; s32 f4; s32 f8; s32 fC; f32 f10; f32 f14; f32 f18; f32 f1C;
    u32 f20; s32 f24; f32 f28; u32 f2C;
} E_3B02A0;
extern void func_003E9450();
extern s32 func_003E8D58(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E7680(s32, f32);
extern s32 func_003E7590(s32, f32, f32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8E38(s32, s32, s32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B5858);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C780);

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_3B0580;
extern S_3B0580 D_00160C40[];
extern void *D_001D89D0;
extern void *D_001D89D4;
/* localdecomp:start func_003B5B38 */
extern void *func_003B5048(s32);
void func_003B5B38(void) {
    D_001D89D0 = func_003B5048(0);
    D_001D89D4 = func_003B5048(2);
    func_003B4528(func_003B42F8(0), (s32)D_001D89D0, (s32)D_001D89D4, D_00160C40->f4954, (s32)D_00160C40->f6F30);
}
/* localdecomp:end func_003B5B38 */

/* localdecomp:start func_003B5B90 */
extern void *func_003B42F8(s32);
 
void func_003B5B90(void) {
    void *o = func_003B42F8(0);
    ((void (*)(void *))(*(void ***)((u8 *)o + 0x4))[3])(o);
}
/* localdecomp:end func_003B5B90 */

/* localdecomp:start func_003B5BC0 */
extern u8 D_0037F830_003B5BC0[];
extern u8 D_0037F690_003B5BC0[];
extern s32 D_001D89B8_003B5BC0;
extern s32 D_001D89E4_003B5BC0;
extern void func_003A5348();
extern s32 func_00381FF0();
extern void func_0011B2E8();
extern s32 func_003B9700();
extern void func_003B96D8();
extern s32 func_003E83C8();
extern void *func_003B4FD0();
extern s32 func_003B51C8(void);
extern void func_003E6FF8(void *p);
__asm__(".extern D_001D89B8_003B5BC0, 4");
__asm__(".extern D_001D89E4_003B5BC0, 4");
void func_003B5BC0(s32 a0, s32 a1) {
    s32 t;
    s32 u;
    u8 *g;
    if (a1 & 0x40) {
        func_003A5348(4, 0, 0);
        g = D_0037F830_003B5BC0;
        t = D_001D89B8_003B5BC0 * 16;
        if (((s32 *)(D_0037F830_003B5BC0 + t))[2] != 0) {
            ((void (*)(s32, u8 *))((s32 *)(g + t))[2])(t, g);
        }
    } else if (a1 & 8) {
        func_0011B2E8(D_0037F690_003B5BC0, func_00381FF0(0xB3B));
 u = func_00381FF0(0x8DE);
 func_003B9700(1, u, func_00381FF0(0x8DF), D_0037F690_003B5BC0, 0);
        func_003B96D8(0x40, 0x10);
        D_001D89E4_003B5BC0 = 5;
    }
    if (a1 & 0x10) {
        func_003A5348(4, 0, 0);
        func_003E83C8(func_003B4FD0());
        func_003E6FF8((void *)func_003B51C8());
    }
}
/* localdecomp:end func_003B5BC0 */

/* localdecomp:start func_003B5CD8 */
typedef struct { s32 a, b, c, d; } E_37B870;
extern E_37B870 D_0037F830[];
extern s32 D_001D89B8;
extern s32 D_001D89BC;
extern s32 D_001D8A00;
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E7A18(s32 arg0, s32 arg1);
void func_003B5CD8(void) {
    s32 v = func_003B9C58(func_003B9BD0(0));
    D_001D89B8 = v;
    if (v < 0) return;
    if (D_001D89BC != v) {
        if (D_001D89BC >= 0) D_001D8A00 = 30;
        else D_001D8A00 = 1;
    }
    if (D_001D8A00 != 0) {
        if (--D_001D8A00 == 0) {
            func_003E7E48(0x1C0003, D_0037F830[D_001D89B8].d);
            func_003E7A18(0x1C0003, 1);
        }
    }
    D_001D89BC = D_001D89B8;
}
/* localdecomp:end func_003B5CD8 */

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B07B8;
extern s32 D_001D89C0;
extern s32 D_001D89C4;
extern s32 D_001D89C8;
extern s32 D_001D89CC;
extern f32 D_001D89D8;
extern f32 D_001D89DC;
extern f32 D_001D89E0;
extern char D_001D8A08[];
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_003BA358();
extern s32 func_003B9E30_003B5D70(void *, s32, s32);
extern s32 func_00381FF0();
extern void func_11B2E8();
INCLUDE_ASM("asm/nonmatchings/text", func_003B5D70);

/* localdecomp:start func_003B6018 */
extern u8 D_0037F790[];
extern s32 D_00143950_b[];
extern char D_001D8A08[];
extern char D_001D8A10[];
extern s32 func_003B64A8(void);
extern s32 func_003B9E30(void *, s32, s32);
extern s32 func_003E7C90(s32, s32);

void func_003B6018(void) {
    s32 i = 0;
    u8 *base = D_0037F790;
    u8 *b = (u8 *)D_00143950_b;
    char *fmt = D_001D8A08;
    s32 yes = 0x175;
    s32 no;
    u8 *p1 = base + 0x20;
    u8 *p2 = base + 0x40;
    u8 *p3 = base + 0x60;
    E_37B870 *e;
    u8 *p;
    void *text;
    func_11B2E8(base, fmt, func_00381FF0(b[0xAD] == 0 ? 0x176 : yes));
    no = 0x176;
    func_11B2E8(p1, fmt, func_00381FF0(b[6] ? yes : no));
    func_11B2E8(p2, fmt, func_00381FF0(*(s32 *)(b + 8) ? 0x237 : 0x236));
    ((s32 (*)())func_11B2E8)(p3, fmt, func_00381FF0(func_003B64A8()));
    e = D_0037F830;
    if (e->a) {
      p = base;
      do {
        text = (void *)func_003B9E30(func_003B9BD0(0), 0, i);
        func_11B2E8(text, D_001D8A10, func_00381FF0(e->a));
        e++;
        text = (void *)func_003B9E30(func_003B9BD0(0), 1, i);
        i++;
        ((s32 (*)())func_11B2E8)(text, D_001D8A08, p);
        p += 0x20;
      } while (e->a);
    }
    func_003E7C90(0x1C0004, func_00381FF0(0x1EBD));
}
/* localdecomp:end func_003B6018 */

extern u8 D_0037F830_003B0A60[];
extern s32 *func_003B9BD0(s32);
extern u8 D_0037F790[];
extern u8 D_0037F810[1];
extern char D_001D8A08[];
extern char D_001D8A10[];
extern s32 D_00143950_b[];
extern s32 func_00381FF0();
extern void func_11B2E8();
extern void func_003E7C90_003B0A60();
extern void *func_003B9E30_003B0A60();

/* localdecomp:start func_003B61D0 */
extern s32 D_00143950_b[];
extern void func_003873C0();
 
void func_003B61D0(void) {
    u8 *b = (u8 *)D_00143950_b;
    b[0xAD] = b[0xAD] == 0;
    func_003873C0();
}
/* localdecomp:end func_003B61D0 */

/* localdecomp:start func_003B6200 */
extern void func_003B6280(void);

void func_003B6200(void) {
    u8 *b = (u8 *)D_00143950_b;
    if (b[0xB7] == 0) {
        b[0xB7] = 1;
    }
    b[0xB7] = (b[0xB7] + 1) % 6;
    func_003B6280();
}
/* localdecomp:end func_003B6200 */

extern s32 D_001D5520_003B0C70;
extern s32 D_001D89B0;
extern s32 D_001D89E4;
extern u8 D_0037F690[];
extern s32 func_00381FF0();
extern void func_11B2E8();
extern void func_003B6438(void);
extern s32 func_003B9700();
extern void func_003B96D8();
extern s32 D_00143950_b[];
extern void func_003B6280(void);

/* localdecomp:start func_003B6250 */
extern u8 D_00143950[];
s32 func_003B6250(void) {
    u8 *p = &D_00143950[0];
    s32 v = p[6] == 0;
    p[6] = v;
    return v;
}
/* localdecomp:end func_003B6250 */

/* localdecomp:start func_003B6268 */
extern s32 D_00143950_b[];

s32 func_003B6268(void) {
    s32 inverted_val = !D_00143950_b[2];
    D_00143950_b[2] = inverted_val;
    return inverted_val;
}
/* localdecomp:end func_003B6268 */
