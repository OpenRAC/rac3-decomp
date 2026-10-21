/* Near miss of func_00393168 with its file's own flags: tools/check.py reports 25 diff
   (the version it replaces: 73).
*/

/* func_00393168 (PAL, frontbin 38DED0.c)

   Retail reaches its globals through lui/%lo (not $gp) and reloads the
   D_001D9EA0 pointer after the call, so the globals are declared as unsized
   arrays of pointers (an unsized array is never small data) and the two
   D_001D9EA0 reads use separate aliases so their addresses are not merged. */

extern S_38E930 *D_001D9EA0_00393168x[];
extern S_38E930 *D_001D9EA0_00393168y[];
extern E_38E930 *D_001D9EAC_00393168x[];
extern s32 D_001A1F08_00393168x[];

/* localdecomp:start func_00393168 */
void func_00393168(s32 n, s32 a1, s32 a2) {
    S_38E930 *p0;
    S_38E930 *p;
    s32 i, j, end, pos, n4;
    s32 b6, b7, sz;

    p0 = D_001D9EA0_00393168x[0];
    if (p0->c[n] == 0) {
        func_00392FD0_00393168(0);
    }
    pos = D_001A1F08_00393168x[0];
    p = D_001D9EA0_00393168y[0];
    n4 = n * 4;
    j = (n != 0) ? p->b[n - 1] : 0;
    end = *(s32 *)((u8 *)p + n4 + 0x34);
    for (i = j; i < end; i++) {
        s32 s = pos >> 8;
        b6 = D_001D9EAC_00393168x[0][i].b6;
        b7 = D_001D9EAC_00393168x[0][i].b7;
        sz = 1 << (b6 + b7);
        func_00397980(D_001D9EAC_00393168x[0][i].w0, s, 0x1B, b6, b7, a2);
        D_001D9EAC_00393168x[0][i].h4 = s;
        pos += sz << 2;
        D_001D5D50 = pos;
    }
}
/* localdecomp:end func_00393168 */
