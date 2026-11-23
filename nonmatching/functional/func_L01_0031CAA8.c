/* functional: high. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 19 words differ in switch dispatch layout only; not byte-identical, behaviour as retail. */
typedef int Q_0031CAA8 __attribute__((mode(TI)));
extern Q_0031CAA8 D_L01_001E29C0[];
extern Q_0031CAA8 D_001A4C60[];
extern int D_L01_001E001C;
void func_L01_0031CAA8(u8 *obj) {
    extern s32 func_L01_00456500(void *,s32);
    extern void func_L01_0031CA18(void *, void *, int, void *);
    extern void func_L01_0031C770(u8 *, u8 *, s8 *, s32);
    Q_0031CAA8 position;
    s8 *vars=*(s8 **)(obj+0x68);
    s32 active=0;
    s32 i;
    s32 *tail;
    s32 *p;
    obj[0x30]=255;
    position=vars[0x7A] ? D_L01_001E29C0[0] : D_001A4C60[0];
    switch(obj[0x95]) {
    case 0:
        for(i=0;i<4;i++) {
            if(((s32 *)vars)[i]!=-1 && func_L01_00456500(&position,((s32 *)vars)[i])) {
                active=1;
                break;
            }
        }
        break;
    case 1:active=1;break;
    default:active=0;break;
    }
    if(active) {
        if(!obj[0xBC]) goto update;
    } else {
        if(obj[0xBC]) goto update;
    }
    if(obj[0x20])return;
update:
    if(active)obj[0xBC]=1;
    else obj[0xBC]=0;
    tail=(s32 *)(vars+0x44);
    obj[0x20]=obj[0xBC]+1;
    for(i=0;i<13;i++) {
        if(((s32 *)(vars+0x10))[i]!=-1)
            func_L01_0031CA18(obj,vars,((s32 *)(vars+0x10))[i],(void *)active);
    }
    for(i=12,p=tail;i>=0;i--,p++) {
        if(*p!=-1)
            func_L01_0031C770(obj,(u8 *)D_L01_001E001C+(*p<<8),vars,active);
    }
}
