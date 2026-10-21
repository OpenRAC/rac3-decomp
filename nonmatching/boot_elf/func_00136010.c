/* US draft of func_00136010 (rac3-uya-decomp func_00136010, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-check-zero-division` (a single-function override). */


/* localdecomp:start func_00136010 */
typedef struct { u32 x0; u32 x4; u32 x8; } S_136010;
extern s32 func_0013A0F8();
extern char D_00152178[];
u32 func_00136010(s32 a, S_136010 *s, u32 c, u32 al) {
    u32 off = (s->x8 + al - 1) / al * al;
    if (s->x0 + s->x4 < off + c) {
        func_0013A0F8(a, D_00152178);
        return 0;
    }
    s->x8 = off + c;
    return off;
}
/* localdecomp:end func_00136010 */
