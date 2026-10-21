/* Near miss of func_003BCA48 with its file's own flags: tools/check.py reports 13 diff
   (the version it replaces: 34).
   What differs: Retail reaches D_001D5B94 (0x1D5B94) and D_001D9D00 (0x1D9D00) through lui/%lo
*/

/* func_003BCA48 (PAL frontbin).
   Retail reaches D_001D5B94 and D_001D9D00 through lui/%lo, not through $gp,
   so they are used through per-function aliases of a type that is not small
   data (size > 8).  D_001D8CB8 / D_001D8CD4 / D_001D8CBC are reached through
   $gp and stay sized. */

/* localdecomp:start func_003BCA48 */
typedef struct { u8 pad[0x22]; u16 f22; } S_16C580c;
extern S_16C580c D_16C580_003BCA48;
__asm__(".extern D_001D8CB8, 4");
__asm__(".extern D_001D8CD4, 4");
__asm__(".extern D_001D8CBC, 4");
extern s32 (*D_001D8CB8)();
extern s32 D_001D8CD4;
extern void (*D_001D8CBC)(s32);
typedef struct { s32 f0; s32 f4; s32 f8; } S_003BCA48;
extern S_003BCA48 D_001D5B94_003BCA48;
extern S_003BCA48 D_001D9D00_003BCA48;
extern void func_003CD058();
extern void func_003CD350();
s32 func_003BCA48(s32 a) {
    s32 r;
    s32 t;
    D_001D5B94_003BCA48.f0 = 6;
    D_16C580_003BCA48.f22++;
    r = D_001D8CB8(a);
    if (D_001D8CD4 & 4) { func_003CD058(); }
    if (D_001D8CD4 & 0x10) { func_003CD350(); }
    if (D_001D8CBC != 0) { D_001D8CBC(a); }
    t = D_001D9D00;
    D_001D9D00_003BCA48.f0 = t + 1;
    return r;
}
/* localdecomp:end func_003BCA48 */
