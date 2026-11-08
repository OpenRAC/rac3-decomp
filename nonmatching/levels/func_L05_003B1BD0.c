/* func_L05_003B1BD0: MATCHES only with --as ps2as (PAL level_05 and NTSC-U); file src/levels/05_daxx/L05_003B1BD0.c
   already holds C compiled without @ps2as (float const 4.84f built inline), so not deliverable as plain MATCH.
   Lead: decide whether the file can take @ps2as. Sibling pattern: func_L07_003CE858 (same table walk). */
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 16");
extern u16 *D_L05_0021DAE0[];
extern s32 D_L05_001DFBD8 __attribute__((section(".sdata")));
extern s32 func_L01_00456250(u8 *);
extern float func_L01_0040E570(u8 *, u8 *);
typedef struct { u8 pad[0x68]; u8 *p68; } A;
u8 *func_L05_003B1BD0(A *a0, u8 *a1)
{
    u8 *st = a0->p68;
    u16 *p;
    u8 *e;
    for (p = D_L05_0021DAE0[*(s32 *)(st + 0x2AC)];
         (*(s32 *)(st + 0x2AC) & 0xFF) != 0xFF && *(s32 *)(st + 0x2AC) <= D_L05_001DFBD8 && p != 0 &&
         (((s16 *)p)[-1] >= 0 || p == D_L05_0021DAE0[*(s32 *)(st + 0x2AC)]);
         p++) {
        e = D_L05_001DFB9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (e[0x20] != 0xFE) {
            if (e[0x20] == 0xFD)
                continue;
            if (func_L01_00456250(e) != 0)
                continue;
            if (func_L01_0040E570(e + 0x10, a1) < 4.84f)
                return e;
        }
    }
    return 0;
}
