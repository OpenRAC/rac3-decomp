/* NTSC-U draft (Claude wave E): C of func_00136B90 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 9 words differ on NTSC-U with the file's flags (NTSC-U twin "func_00136B90").
 * Study aid: it uses volatile, which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: libipu-style DMA send (struct {volatile done, err, size, addr, n} at sp+0x20 passed as the AddIntcHandler arg func_0011EB40(3, func_00137228, 0, &st), D_STAT/D4_MADR/QWC/CHCR/IPU_CMD literal volatile registers, cmd[8] at sp+0, wait loops on done<n and ...
 */
#include "common.h"

/* localdecomp:start func_00136B90 */
typedef struct Ipu_00136B90 {
    volatile s32 done;
    s32 err;
    s32 size;
    s32 addr;
    s32 n;
} Ipu_00136B90;
typedef struct Mp_00136B90 {
    u8 pad0[0x868];
    s32 f868;
} Mp_00136B90;
extern s32 func_0011EB40();
extern void func_0011EB50();
extern void func_0011F9A8();
extern void func_0011F940();
extern void func_00137228();
extern char D_001521E8[];

void func_00136B90(Mp_00136B90 *mp, u32 addr, s32 size)
{
    s32 cmd[8];
    Ipu_00136B90 st;
    s32 id;
    s32 di;

    st.n = size / 0x3FF + 1;
    st.err = 0;
    st.done = 0;
    st.size = size;
    st.addr = (addr + 0xFFC00) & 0xFFFFFFF;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    id = func_0011EB40(3, func_00137228, 0, &st);
    *(volatile u32 *)0x1000E010 = 8;
    func_0011F9A8(3);
    di = func_00124920();
    *(volatile u32 *)0x1000B010 = addr & 0xFFFFFFF;
    *(volatile u32 *)0x1000B020 = 0xFFC0;
    *(volatile u32 *)0x1000B000 = 0x100;
    if (di) {
        func_00124970();
    }
    *(volatile u32 *)0x10002000 = 0x700003FF;
    cmd[0] = 4;
    func_00135D50(mp->f868, cmd);
    while (st.done < st.n) {
    }
    if (st.err) {
        func_0013A0F8(mp, D_001521E8);
    }
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    func_0011F940(3);
    func_0011EB50(3, id);
}
/* localdecomp:end func_00136B90 */
