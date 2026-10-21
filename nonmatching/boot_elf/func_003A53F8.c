/* US draft of func_003A53F8 (rac3-uya-decomp func_003A52B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A53F8 */
__asm__(".extern D_001D6E14, 1");
typedef int u128_39FBD8 __attribute__((mode(TI)));
extern void func_003A41C8(void *, void *, void *, void *);
typedef struct 
{
  u8 p0[0xC4];
  u8 *c4;
  u8 pC8[0x18];
  u128_39FBD8 qE0;
  u128_39FBD8 qF0;
} E_39FBD8;
typedef struct { u8 b[0x80]; } R_39FBD8;
extern s32 D_001D5B98_003A53F8;
extern u8 D_001D6E14;
extern u8 D_00222480[];
extern s32 func_00382848(s32);
s32 func_003A53F8(u8 *s, u32 flags, u8 *src, u8 *pos, s32 vol)
{
  s32 r;
  s32 off;
  s32 v = 0;
  s32 empty = s[0x18] == 0;
  u128_39FBD8 *new_var;
  s32 a;
  s32 b;
  s32 c;
  if (!(flags & 4))
  {
    if ((empty ^ 1) != 0)
      goto fail;
  }
  else
    if (empty)
      goto fail;
  r = func_003A5380(src);
  if (r >= 0)
  {
    {
      u8 *e;
      off = r * 128;
      e = (u8 *) (off + ((s32) D_1A30B0));
      *((s32 *) (e + 0x114)) = 0;
      *((u8 **) (e + 0xC4)) = s;
      new_var = (u128_39FBD8 *) pos;
      *((s16 *) (e + 0xC8)) = *((s16 *) (s + 0x1A));
      *((s16 *) (e + 0xCA)) = -1;
      *((f32 *) (e + 0x110)) = -1.0f;
      *((s16 *) (e + 0xCC)) = vol;
      *((s32 *) (e + 0xDC)) = 0;
      *((s32 *) (e + 0x100)) = 0;
      __asm__("sq $0,%0" : "=m"(*((u128_39FBD8 *) (off + (D_1A30B0 + 0xF0)))));
      if ((pos != 0) || (src != 0))
      {
        if (src != 0)
        {
          ((u128_39FBD8 (*)[8]) D_1A30B0)[r][14] = *((u128_39FBD8 *) (src + 0x10));
          *((f32 *) (e + 0xE8)) += 1.0f;
        }
        else
        {
          ((u128_39FBD8 (*)[8]) D_1A30B0)[r][14] = *new_var;
        }
      }
      else
      {
        flags |= 0x11;
        __asm__("sq $0,%0" : "=m"(*((u128_39FBD8 *) ((r * 128) + (D_1A30B0 + 0xE0)))));
      }
    }
    if (!(flags & 0x10))
    {
    if (D_001D5B98_003A53F8 != 0)
    {
      s32 i;
      for (i = 0; i < (D_001D5B98_003A53F8 + 1); i++)
      {
        f32 *o;
        f32 f = func_0038D2E0((r * 128) + (D_1A30B0 + 0xE0), D_00222480 + i * 0x460);
        o = (f32 *)((E_39FBD8 *)(D_1A30B0 + (r * 128)))->c4;
        v += func_003A40F0(o, (void *) 1, f, o[0], o[1]);
      }

      {
        s32 lim = 0x400 - (*((s32 *) 0x1D52E4));
        if (v >= lim)
        {
          v = lim;
        }
      }
    }
    else
    {
      v = ((s32 (*)(void *, void *, void *, void *)) func_003A41C8)((r * 128) + (D_1A30B0 + 0xC0), (r * 128) + (D_1A30B0 + 0xE0), 0, 0);
    }
    }
    else
    {
      v = vol;
    }
    if (v < 0x20)
    {
      return -1;
    }
    else
    {
      {
        u8 *e = (u8 *) ((r * 128) + ((s32) D_1A30B0));
        *((u32 *) (e + 0x118)) = flags;
        e[0xD0] = 7;
        *((s16 *) (e + 0xCE)) = 0;
      }
      a = *((s32 *) (s + 0x14));
      b = *((s32 *) (s + 0x10));
      if (a != b)
      {
        c = func_00382848(a - b) + (*((s32 *) (s + 0x10)));
      }
      else
      {
        c = a;
      }
      {
        u8 *e = (u8 *) ((r * 128) + ((s32) D_1A30B0));
        u8 t = D_001D6E14;
        u8 t1 = t + 1;
        *((s32 *) (0xD4 + e)) = c;
        *((u32 *) (e + 0xC0)) = 0xFFFFFFFF;
        D_001D6E14 = t1;
        *((s32 *) (e + 0xD8)) = 0;
        e[0xD3] = t;
      }
    }
  }
  else
  {
    r = -1;
  }
  return r;
  fail:
  return -1;
}
/* localdecomp:end func_003A53F8 */
