/* PAL near miss (Codex wave 7): near miss: 49 words differ with the file's flags.
 * Worker's note: 49 diff wrapper10.log: buffer mult destination, global-address formation, fallback loop allocation and handle-store address; best retained after 11 compiles
 */
#include "common.h"
/* localdecomp:start func_L01_0042D110 */
typedef struct { s32 id; u8 pad[12]; s32 flag; } Entry_0042D110;
typedef struct { u8 pad[0x4590]; Entry_0042D110 e[48]; } Table_0042D110;
extern Table_0042D110 D_00160C40_0042D110;
typedef struct {
    u8 pad0[0x14]; s16 current, slot;
    u8 pad18[0x18]; s32 handle; s32 resident[3];
    u8 data[3][0xc800];
} State_0042D110;
extern State_0042D110 D_0016C690;
extern u8 D_001A30B0[];
extern u8 D_001D6DF0_sda[];
extern s32 D_L01_001E1060, D_L01_001E1070;
extern u8 *D_001D4B38;
__asm__(".extern D_001D6DF0_sda, 4");
__asm__(".extern D_L01_001E1060, 16");
__asm__(".extern D_L01_001E1070, 16");
__asm__(".extern D_001D4B38, 16");
void func_L01_0042D110(s32 id) {
    extern void func_003A92F0(s32);
    extern void func_L01_0042CD88(s32,s32);
    extern void func_L01_004369B8(void *,void *,s32);
    extern void func_0013BF00(s32);
    extern s32 func_0013B620(void);
    extern s32 func_0013BD58(void *);
    extern void func_0013BED0(void);
    extern void func_L01_0042CE68(s32,s32,void *);
    s32 index, slot, i;
    u8 *buffer;
    u8 *row;
    for (index=0;index<48;index++) {
        if (D_00160C40_0042D110.e[index].id==id) break;
    }
    if (index==48) return;
    if (index==D_0016C690.current) return;
    D_0016C690.current=index;
    for (slot=0;slot<3;slot++) {
        if (D_0016C690.resident[slot]==index) break;
    }
    func_003A92F0(1);
    if (slot==3) { slot=0; func_L01_0042CD88(id,0); }
    {
        State_0042D110 *state=&D_0016C690;
        u8 *bytes=(u8 *)state;
        buffer=bytes+0x40;
        buffer+=slot*0xc800;
        state->slot=slot;
    }
    if ((s32)buffer<0x100000) {
        u8 *destination=(u8 *)(D_L01_001E1060+D_L01_001E1070-0xc800);
        func_L01_004369B8(destination,buffer,0xc80);
        buffer=destination;
    }
    row=D_001A30B0;
    for (i=51;i>=0;i--,row+=0x80) {
        u8 *ptr=*(u8 **)(row+0xc4);
        if (ptr && *(s32 *)(ptr+0x1c)==4) *(u8 **)(row+0xc4)=D_001D6DF0_sda;
    }
    if (D_0016C690.handle) {
        func_0013BF00(D_0016C690.handle);
        while (func_0013B620()) {}
    }
    if (D_00160C40_0042D110.e[index].flag) {
        s32 handle=func_0013BD58(D_001D4B38+slot*0xc800);
        D_0016C690.handle=handle;
        *(s32 *)(D_001A30B0+0xa0)=handle;
    } else D_0016C690.handle=0;
    func_0013BED0();
    func_L01_0042CE68(id,index,buffer);
}
/* localdecomp:end func_L01_0042D110 */
