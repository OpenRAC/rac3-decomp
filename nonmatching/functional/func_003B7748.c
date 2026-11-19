/* functional: high. Codex PAL draft verified against the assembly (time divisor 216000 = 60*3600, minutes = value/3600 - hours*60, clamps 99:59, 9999999 and 99, message table D_0037FA58/5C indexed (state%60)*2, three element ids per slot 0x4C0008+i, 0x4C0040+i, 0x4C0044+i, 0x4C0048+i). Same call sequence as retail; 255 words differ (regalloc). Compiles with --no-context: in its file context check.py hits a pre-existing conflict between two func_0011B2E8 declarations (context line 16), not from this C. */
/* localdecomp:start func_003B7748 */
extern char D_001D8AE8[],D_001D8AF0[],D_001D8B00[],D_001D8B10[],D_001D8B18[],D_001D8B28[],D_001D8B30[];
extern s32 D_0037FA58[],D_0037FA5C[];
extern s32 D_001D8AC0[2];
extern u8 D_00142430_003B7748[];
void func_003B7748(void) {
    extern s32 func_003E8128(s32,s32);
    extern s32 func_003BB4D0(u32);
    extern s32 func_003823D0();
    extern void func_0011B2E8();
    s32 func_003BB500(s32);
    extern s32 func_003E8200(s32,s32);
    s32 func_003E7DD0(s32,s32);
    s32 i,offset,textOffset,id,state,text,hours,minutes,value,message;
    u8 *slot;
    offset=0;
    textOffset=0;
    id=0x4C0008;
    slot=(u8 *)D_00142430_003B7748+0x38;
    for (i=0;i<4;i++) {
        func_003E8128(id,0x80808080);
        state=*(s32 *)(slot-8);
        if(state<=0) {
            text=func_003BB4D0(0)+textOffset;
            message=func_003823D0(0x238);
            func_0011B2E8((char *)text,D_001D8AE8,message);
            func_0011B2E8((char *)(func_003BB4D0(1)+textOffset),D_001D8AF0);
            func_0011B2E8((char *)(func_003BB4D0(2)+textOffset),D_001D8B00,0,0);
            func_0011B2E8((char *)(func_003BB4D0(3)+textOffset),D_001D8B10);
            func_003E8200(id,func_003BB500(0));
            func_003E7DD0(i+0x4C0040,1);
            func_003E7DD0(i+0x4C0044,0);
        } else {
            if ((u32)(state-1)<2 || state==4 || state==8 || state==27 || state==28 || state==9 || state==29 || state==5 || state==13 || state==23 || state==10 || state==18 || state==14) {
                if (state>0) message=D_0037FA5C[(state%60)*2];
                else message=D_0037FA58[3];
            } else {
                if(state>0) message=D_0037FA58[(state%60)*2];
                else message=D_0037FA58[2];
            }
            text=func_003823D0(message);
            func_0011B2E8((char *)(func_003BB4D0(0)+textOffset),D_001D8AE8,text);
            func_0011B2E8((char *)(func_003BB4D0(1)+textOffset),D_001D8B18,((u8 *)D_00142430_003B7748)[offset+0x45],((u8 *)D_00142430_003B7748)[offset+0x46],((u8 *)D_00142430_003B7748)[offset+0x47]);
            value=*(s32 *)((u8 *)D_00142430_003B7748+offset+0x3C);
            hours=value/216000;
            minutes=value/3600-hours*60;
            if(hours>=100) {hours=99;minutes=59;}
            func_0011B2E8((char *)(func_003BB4D0(2)+textOffset),D_001D8B00,hours,minutes);
            value=*(s32 *)((u8 *)D_00142430_003B7748+offset+0x34);
            if(value>9999999) value=9999999;
            func_0011B2E8((char *)(func_003BB4D0(3)+textOffset),D_001D8B28,value);
            value=func_003BB500(state);
            if(value<=0) {
                func_003E8200(id,func_003BB500(0));
                func_003E7DD0(i+0x4C0040,1);
            } else {
                func_003E8200(id,value);
                func_003E7DD0(i+0x4C0040,0);
            }
            value=*(s32 *)slot;
            if(value>=100) value=99;
            if(value!=0) {
                func_003E7DD0(i+0x4C0044,1);
                func_003E7DD0(i+0x4C0048,1);
                func_0011B2E8((char *)D_001D8AC0+i*4,D_001D8B30,value);
            } else {
                func_003E7DD0(i+0x4C0044,0);
                func_003E7DD0(i+0x4C0048,0);
            }
        }
        textOffset+=0x20;
        offset+=0x1C;
        id++;
        slot+=0x1C;
    }
}
/* localdecomp:end func_003B7748 */
