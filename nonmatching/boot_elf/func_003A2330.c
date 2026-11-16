/* PAL near miss (Codex wave 10): near miss: 27 words differ with the file's flags.
 * Worker's note: 27 diff in 06-detail.log (06-aligned.log); case-2 allocation/store order, channel-0 volume and tail state-base allocation remain; 10 compiles; decoded switch evidence func_003A2330.switch.txt
 */
#include "common.h"
/* localdecomp:start func_003A2330 */
typedef struct {
    u8 pad0[4]; s16 command; u8 busy, disabled;
    s32 file; s32 padC; s32 size, track;
    void (*callback)(s32,s32); s32 callbackArg;
    s32 pad20; s32 request, requestArg;
    s16 update; u8 pad2E[2];
    s32 duration, ramp, timer;
    s16 pendingTrack,pendingIndex;
    u8 pad40[4];
    u32 handle; s16 song, volume, flags, state, protection;
    u8 pad52[0x94-0x52];
    s32 requestState;
    u8 pad98[6]; s16 requestStatus;
    u8 padA0[0xB8-0xA0]; s32 idleTimer;
    u32 secondHandle; u8 padC0[6]; s16 secondState,secondProtection; u8 padCA[2];
    s16 secondReady; u8 padCE[6]; s32 fadeTimer;
} State_003A2330;
extern State_003A2330 D_001CCFD0_003A2330;
extern S_39CC98 D_001CD014_003A2330, D_001CD03C_003A2330;
extern f32 D_001D6DB0;
extern f32 D_001D6DB4;
void func_003A2330(void) {
    extern void func_003A1D30(s32,s32,s32);
    extern void func_003A1E28(s32,s32,s32);
    extern void func_003A1C38(s32,s32,s32);
    extern int func_003A1F40(int,int,int,int);
    extern s32 func_0038CEB0(void *);
    extern void func_003A19D0(s32,s32,s32,s32 *,s32);
    extern s32 func_0013C2C0(s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_003A2E90(s32,long);
    extern void func_0013CC40(s32);
    extern void func_0013C2A0(s32,s32,s32,s32,s32,s32);
    extern void func_003A57E8(s32,s32);
    extern void func_003A2120(S_39CC98 *);
    extern s32 func_0013CDF0(s32);
    extern s32 func_003A2998(s32,s32,s32);
    s32 volume;
    if(D_001CCFD0_003A2330.disabled) return;
    if(!(D_001CCFD0_003A2330.protection & 0x8000) && !(D_001CCFD0_003A2330.state & 0x8000)) {
        if(D_001CCFD0_003A2330.handle==0) {
            if((D_001CCFD0_003A2330.flags & 1) && D_001CCFD0_003A2330.pendingTrack==-1) {
                func_003A1D30(D_001CCFD0_003A2330.song,D_001CCFD0_003A2330.flags,D_001CCFD0_003A2330.volume);
                goto afterStart;
            }
        }
        if(D_001CCFD0_003A2330.handle && D_001CCFD0_003A2330.handle!=0xFFFFFFFFu && D_001CCFD0_003A2330.state==8)
            func_003A1E28(D_001CCFD0_003A2330.song,D_001CCFD0_003A2330.flags,D_001CCFD0_003A2330.volume);
    }
afterStart:
    if(func_0038CEB0(&D_001CCFD0_003A2330.timer) && D_001CCFD0_003A2330.pendingTrack!=-1 && D_001CCFD0_003A2330.update==0) {
        if(D_001CCFD0_003A2330.song!=D_001CCFD0_003A2330.pendingTrack) {
        if(D_001CCFD0_003A2330.pendingIndex==-1) {
            if(D_001CCFD0_003A2330.state & 0x8000) {
                D_001CCFD0_003A2330.update=3;
                D_001CCFD0_003A2330.state=5;
            } else {
                D_001CCFD0_003A2330.ramp=12;
                D_001CCFD0_003A2330.fadeTimer=12;
                D_001CCFD0_003A2330.update=6;
            }
            D_001CCFD0_003A2330.timer=250;
        } else if(func_003A1F40(D_001CCFD0_003A2330.pendingTrack,D_001CCFD0_003A2330.pendingIndex,D_001CCFD0_003A2330.flags,D_001CCFD0_003A2330.volume)) {
            D_001CCFD0_003A2330.timer=350;
        }
        } else D_001CCFD0_003A2330.pendingTrack=-1;
    }
afterTrack:
    if(D_001CCFD0_003A2330.request>=0) {
        if(D_001CCFD0_003A2330.requestState==0) {
            func_003A19D0(D_001CCFD0_003A2330.request,0,D_001CCFD0_003A2330.requestArg,&D_001CCFD0_003A2330.requestState,1024);
            D_001CCFD0_003A2330.requestArg=0;
            D_001CCFD0_003A2330.request=-1;
        } else if((u32)((u16)D_001CCFD0_003A2330.requestStatus-6)>=2u) D_001CCFD0_003A2330.requestStatus=5;
    }
    if(D_001CCFD0_003A2330.state!=9 && D_001CCFD0_003A2330.handle!=0xFFFFFFFFu && !(D_001CCFD0_003A2330.protection & 0x8000) &&
       !(D_001CCFD0_003A2330.state & 0x8000) &&
       (D_001CCFD0_003A2330.pendingIndex==-1 || (!(D_001CCFD0_003A2330.secondProtection & 0x8000) && !(D_001CCFD0_003A2330.secondState & 0x8000)))) {
        switch(D_001CCFD0_003A2330.update) {
        case 6: {
            u32 handle=D_001CCFD0_003A2330.handle;
            s32 v=D_001CCFD0_003A2330.volume*D_001CCFD0_003A2330.fadeTimer/D_001CCFD0_003A2330.ramp;
            D_001CCFD0_003A2330.handle=0xFFFFFFFFu;
            func_0013C2C0(handle,5,v,0,0,0,(s32)func_003A2E90,(s32)&D_001CCFD0_003A2330.handle);
            if(func_0038CEB0(&D_001CCFD0_003A2330.fadeTimer)) {D_001CCFD0_003A2330.update=3;D_001CCFD0_003A2330.state=5;}
            break;
        }
        case 2: {
            s32 v=D_001CCFD0_003A2330.volume*(D_001CCFD0_003A2330.ramp-(D_001CCFD0_003A2330.duration-D_001CCFD0_003A2330.fadeTimer))/D_001CCFD0_003A2330.ramp;
            if(v<=0 || (!(D_001CCFD0_003A2330.secondState==4 && D_001CCFD0_003A2330.secondReady!=0) && !D_001CCFD0_003A2330.secondHandle) || !D_001CCFD0_003A2330.handle) {
                D_001CCFD0_003A2330.state=5; D_001CCFD0_003A2330.update=3;
            } else if(D_001CCFD0_003A2330.state!=9) {
                u32 handle=D_001CCFD0_003A2330.handle;
                u32 *slot=&D_001CCFD0_003A2330.handle;
                D_001CCFD0_003A2330.handle=0xFFFFFFFFu;
                func_0013C2C0(handle,5,v,0,0,0,(s32)func_003A2E90,(s32)slot);
            }
            break;
        }
        case 3:
            if(D_001CCFD0_003A2330.state==0 && (D_001CCFD0_003A2330.secondReady!=0 || D_001CCFD0_003A2330.secondHandle==0)) {
                func_003A1C38(D_001CCFD0_003A2330.pendingTrack,D_001CCFD0_003A2330.flags,D_001CCFD0_003A2330.volume);
                D_001CCFD0_003A2330.pendingTrack=-1;D_001CCFD0_003A2330.update=4;
            }
            break;
        case 4:
            if(D_001CCFD0_003A2330.state==3 && (D_001CCFD0_003A2330.fadeTimer<D_001CCFD0_003A2330.ramp || D_001CCFD0_003A2330.secondState!=4 || (!D_001CCFD0_003A2330.secondReady && !D_001CCFD0_003A2330.secondHandle))) {
                func_0013CC40(D_001CCFD0_003A2330.handle);
                D_001CCFD0_003A2330.state=8;D_001CCFD0_003A2330.update=5;
            }
            break;
        case 5:
            if(D_001CCFD0_003A2330.secondState!=4 || !D_001CCFD0_003A2330.secondReady) D_001CCFD0_003A2330.update=0;
            break;
        }
    }
    volume=(s32)(D_001D6DB0*1024.0f);
    if(D_001CD014_003A2330.fA==4 && D_001CD014_003A2330.f0!=0xFFFFFFFFu) func_0013C2A0(D_001CD014_003A2330.f0,1,volume,0,0,0);
    volume=(s32)(D_001D6DB4*1024.0f);
    if(D_001CD03C_003A2330.fA==4 && D_001CD03C_003A2330.f0!=0xFFFFFFFFu && *(s32 *)((u8 *)&D_001CD03C_003A2330+0x20)!=-1)
        func_003A57E8(*(s32 *)((u8 *)&D_001CD03C_003A2330+0x20),volume);
    func_003A2120(&D_001CD014_003A2330);
    func_003A2120((S_39CC98 *)((u8 *)&D_001CD014_003A2330+0x78));
    func_003A2120((S_39CC98 *)((u8 *)&D_001CD014_003A2330+0x28));
    func_003A2120((S_39CC98 *)((u8 *)&D_001CD014_003A2330+0x50));
    if(D_001CCFD0_003A2330.requestStatus==2 && D_001CCFD0_003A2330.idleTimer<0) {
        if((u32)(*(u16 *)((u8 *)&D_001CCFD0_003A2330+0x76)-6)>=2u) *(s16 *)((u8 *)&D_001CCFD0_003A2330+0x76)=5;
        if((u32)((u16)D_001CCFD0_003A2330.requestStatus-6)>=2u) D_001CCFD0_003A2330.requestStatus=5;
    } else D_001CCFD0_003A2330.idleTimer--;
    if(D_001CCFD0_003A2330.busy) {
        if(func_0013CDF0(1)==0) {
            D_001CCFD0_003A2330.command=0;
            D_001CCFD0_003A2330.busy=0;
            if(D_001CCFD0_003A2330.callback) {
                void (*cb)(s32,s32)=D_001CCFD0_003A2330.callback;
                s32 arg=D_001CCFD0_003A2330.callbackArg;
                D_001CCFD0_003A2330.callback=0;D_001CCFD0_003A2330.callbackArg=0;
                cb(arg,0);
            }
        }
    } else if(D_001CCFD0_003A2330.command==2) {
        s32 command=D_001CCFD0_003A2330.command;
        D_001CCFD0_003A2330.command=0;
        func_003A2998(D_001CCFD0_003A2330.track,D_001CCFD0_003A2330.file,D_001CCFD0_003A2330.size);
        if(D_001CCFD0_003A2330.command==0) D_001CCFD0_003A2330.command=command;
    }
}
/* localdecomp:end func_003A2330 */
