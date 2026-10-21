/* US draft of func_003B6588 (rac3-uya-decomp func_003B10A8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B6588 */
typedef struct { u8 b[8]; } B8_3B10A8;
typedef struct { s32 f0, f4, f8, fC; B8_3B10A8 f10; s32 f18; } E_3B10A8;
typedef struct { u8 p0[0x30]; E_3B10A8 e[11]; u8 p1[0x17C - 0x30 - 11 * 0x1C]; s32 f17C; } S_3B10A8;
typedef struct { s32 f0; u8 p[0x2E]; u8 f32; } T_3B10A8;
__asm__(".extern D_001D8A9C, 4");
__asm__(".extern D_001D8AB4, 4");
__asm__(".extern D_001D8AB8, 1");
extern S_3B10A8 D_00142430_003B6588;
extern T_3B10A8 D_00142660_003B6588;
extern B8_3B10A8 D_001D4BE0_003B6588;
extern s32 D_001D545C_003B6588;
extern s32 D_001D5528;
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern u8 D_001D8AB8;
extern void func_0039BEF0(s32, s32);
void func_003B6588(void) {
    s32 h = D_001D8A9C;
    s32 i;
    if (h != 0) {
        i = D_001D8AB4;
        D_00142430_003B6588.f17C = 1;
        D_00142430_003B6588.e[i].f4 = D_00142660_003B6588.f0;
        D_00142430_003B6588.e[i].f0 = D_001D545C_003B6588;
        D_00142430_003B6588.e[i].fC = D_001D5528;
        { B8_3B10A8 *q = &D_00142430_003B6588.e[i].f10; *q = D_001D4BE0_003B6588; }
        D_00142430_003B6588.e[i].f8 = D_00142660_003B6588.f32;
        func_0039BEF0(h, -1);
        D_001D8AB8 = 1;
    }
}
/* localdecomp:end func_003B6588 */
