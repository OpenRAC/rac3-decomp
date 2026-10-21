/* Near miss of func_003A3B40 with its file's own flags: tools/check.py reports 19 diff
   (the version it replaces: 239).
*/

/* PAL port of func_003A3B40 (NTSC decomp func_003A3A00).
 *
 * The retail build reaches two of the globals through lui/%lo instead of $gp:
 *   - D_001D52FC is loaded with "lui $2, %hi(D_001D52FC); lw $2, %lo(D_001D52FC)($2)"
 *     in both places, so it is declared as an unsized array (never small data).
 *   - the second store to D_001D4CF4 ("lui $at, %hi(...); sb $2, %lo(...)(%at)")
 *     is absolute too, while the first one (in a branch delay slot) is $gp-relative,
 *     so the two accesses need two declarations: a sized scalar and an unsized one.
 */

/* localdecomp:start func_003A3B40 */
typedef struct P_3A3A00 {
    u8 pad[0x188]; u8 f188; u8 f189; u8 pad18A[0x198 - 0x18A];
    s32 f198; s32 f19C; s32 f1A0; u8 pad1A4[8]; s32 f1AC; s32 f1B0; u8 pad1B4[8]; s32 f1BC;
    u8 pad1C0[0x1DC - 0x1C0]; s32 f1DC; u8 pad1E0[0x348 - 0x1E0]; s32 f348;
    u8 pad34C[0x54C - 0x34C]; u8 f54C; u8 pad54D[3]; u8 f550; u8 f551[6]; u8 f557; u8 f558; u8 pad559[3];
    s32 f55C; s32 f560; s32 f564; u8 pad568[4];
    void (*f56C)(struct P_3A3A00 *, u8 *, s32, s32); s32 f570; u8 f574; u8 f575;
} P_3A3A00;
extern P_3A3A00 *D_001D52FC_003A3B40;
extern u8 D_001D4CF4;
extern u8 D_001D6DF0[8];
extern void func_003A31C8(Pad_3A3088 *, u8 *, s32);
extern s32 func_12F470(s32, s32);
extern s32 func_12F728(s32, s32, s32, s32);
extern s32 func_12F860(s32, s32, s32, s32);
extern s32 func_12F5A8(s32, s32);
extern s32 func_12F608(s32, s32, s32, s32);
extern s32 func_12F9E0(s32, s32, u8 *);
extern s32 func_12FC18(s32, s32);
extern s32 func_12FC78(s32, s32);
extern s32 func_12EBB8(s32);
extern s32 func_12F3F8(s32, s32, u8 *);
extern s32 func_12F918(s32, s32, u8 *);
/* unsized arrays: the compiler reaches these through lui/%lo, not $gp */
extern P_3A3A00 *D_001D52FC_003A3B40_lui[];
extern u8 D_001D4CF4_lui[];
void func_003A3B40(P_3A3A00 *o) {
    s32 port, slot, t, r;
    o->f1A0 = 0;
    t = o->f1B0;
    port = o->f54C;
    slot = o->f557;
    o->f1B0 = 0;
    o->f1AC = o->f348;
    o->f1BC = t;
    r = func_12F470(port, slot);
    o->f19C = r;
    if (r == 0) o->f198 = 0;
    if (o == D_001D52FC_003A3B40_lui[0]) D_001D4CF4 = 0;
    switch (o->f198) {
    case 0:
        if (o == D_001D52FC_003A3B40_lui[0]) D_001D4CF4_lui[0] = 1;
        if (o->f19C != 6 && o->f19C != 2) {
            if (o->f56C) o->f56C(o, D_001D6DF0, 0x20, o->f570);
            func_003A31C8((Pad_3A3088 *)o, D_001D6DF0, 0x20);
            o->f558 = 0;
            break;
        }
        r = func_12F728(port, slot, 1, 0);
        o->f560 = r;
        if (r == 0) break;
        r = func_12F728(port, slot, 2, 0);
        o->f564 = r;
        if (r > 0) o->f560 = r;
        o->f55C = 0;
        switch (o->f560) {
        case 4: o->f198 = 0x28; break;
        case 7: o->f198 = 0x46; break;
        default: o->f198 = 0x63; break;
        }
        break;
    case 40:
        if (func_12F728(port, slot, 2, 0) == 0) {
            o->f198 = 0x63;
            break;
        }
        o->f198++;
    case 41:
        if (func_12F860(port, slot, 1, 3) != 1) break;
        o->f198++;
        break;
    case 42:
        if (func_12F5A8(port, slot) == 1) o->f198--;
        if (func_12F5A8(port, slot) == 0) o->f198 = 0;
        break;
    case 70: {
        s32 i;
        if (func_12F608(port, slot, -1, 0) == 0) o->f198 = 0x63;
        o->f551[1] = 1;
        o->f551[0] = 0;
        for (i = 2; i < 6; i++) o->f551[i] = 0xFF;
        if (func_12F9E0(port, slot, o->f551) == 0) break;
        o->f198++;
        break;
    }
    case 72:
        if (func_12FC18(port, slot) == 0) {
            o->f55C = 0;
            o->f198 = 0x63;
        } else {
            o->f198 = 0x4C;
        }
        break;
    case 76:
        if (func_12FC78(port, slot) != 0) {
            o->f198++;
            break;
        }
        o->f198 = 0x48;
        break;
    case 71:
    case 77:
        if (func_12F5A8(port, slot) == 1) o->f198--;
        if (func_12F5A8(port, slot) != 0) break;
        o->f198++;
        break;
    case 78:
        o->f198 = 0x63;
        break;
    default:
        if (o->f558 == 0) o->f550 = func_12EBB8(o->f54C);
        o->f558 = 1;
        if (o->f19C == 6 || o->f19C == 2) {
            u8 *buf = &o->f574;
            s32 v;
            if (func_12F3F8(port, slot, buf) == 0) break;
            if (o->f574 == 0) {
                s32 n = (o->f575 & 0xF) * 2 + 2;
                if (n >= 21) n = 20;
                if (o->f56C) o->f56C(o, buf, n, o->f570);
                func_003A31C8((Pad_3A3088 *)o, buf, n);
                o->f1DC = o->f575;
            }
            v = o->f1DC;
            if (v > 0 && o->f55C != 0 && v != o->f55C) {
                o->f55C = 0;
                o->f198 = 0;
            } else if (v > 0) {
                o->f55C = v;
            }
            func_12F918(port, slot, &o->f188);
            o->f188 = 0;
            o->f189 = 0;
        }
        break;
    }
}
/* localdecomp:end func_003A3B40 */
