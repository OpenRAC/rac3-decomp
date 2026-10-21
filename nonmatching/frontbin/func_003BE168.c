/* Near miss of func_003BE168 with its file's own flags: tools/check.py reports 5 diff
   (the version it replaces: 34).
*/

/* PAL candidate for func_003BE168 (frontbin).
   Based on the US draft (rac3-uya-decomp func_003B8C70, commit 13cf5c5), names moved to PAL
   addresses where known.

   The US matched this with @ps2as; with this file's own flags (split addresses, default
   assembler) the globals must be declared so that gcc builds their addresses itself:

   - The load of D_001D6E90 comes from an unsized array alias, which is never small data, so
     gcc splits the address: `lui $a0, %hi(...)` + `lw $a0, %lo(...)($a0)`, the shape retail has.
     The plain name is sized (`extern s32 D_001D6E90;`), so it would come through $gp.
   - The two stores use the literal addresses of the globals: gcc folds the low half into the
     store offset and keeps the high half in $at, the shape retail has
     (same trick as func_003BDF40 / func_003BE3B8 in this file). */

/* localdecomp:start func_003BE168 */
void func_003A7480(s32);
void func_003A7618(s32);
extern s32 D_001D6E90_003BE168[];
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B8C70_003B8C70;
extern S_001CCFD0_003B8C70_003B8C70 D_001CCFD0_003BE168[];

void func_003BE168(void) {
    s32 v = *(s32 *)0x1D6E90;
    if (v != 0) {
        D_001CCFD0_003BE168->f7 = 0;
        switch (v) {                       /* irregular */
        case 17:
            func_003A7480(0x11);
            break;
        case 18:
            func_003A7618(0x12);
            break;
        }
        D_001CCFD0_003BE168->f7 = 1;
        *(s32 *)0x1D5B94 = 6;
        *(s32 *)0x1D6E90 = 0;
    }
}
/* localdecomp:end func_003BE168 */
