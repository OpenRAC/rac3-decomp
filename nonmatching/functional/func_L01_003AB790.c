/* functional: medium. Draft references D_L01_00237800.x464, D_001D545C etc. that come from the file context */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003AB790;
extern u8 D_001BBC40[];
typedef struct { u8 pad[0x464]; u8 bytes[1]; } T_003AB790;
extern T_003AB790 D_L01_00236B90;
typedef struct { u8 pad[0xC70]; s32 path[4]; s32 ids[4]; } D_003AB790;
extern u8 D_L01_001DFE80[] __attribute__((section(".sdata")));
extern u8 *D_L01_0021F6C0[];
__asm__(".extern D_L01_001DE3C4,4");
extern f32 D_L01_001DE3C4 __attribute__((section(".sdata")));
extern u8 *D_L01_001E0100;
void func_L01_003AB790(u8 *o, u8 *d) {
    extern void func_L01_003AD850(u8 *,u8 *);
    extern void func_L01_004450F0(S_3A9AC0m *,int,int);
    extern f32 func_0038CF00(void *,void *);
    extern void func_0038CF68(u8 *,Vec4 *,f32);
    Vec4 tmp, tmp2;
    s32 i, end;
    u8 *points, *item;
    f32 f;
    func_L01_003AD850(o,d);
    i=*(s32 *)(d+0xD0C)+1;
    while(i<4 && ((D_003AB790 *)d)->ids[i]==-1) i++;
    end=i==4;
    if(end) {
        if(*(s32 *)(d+0xC50)==-1) {
            if(*(s32 *)(d+0xC5C) && !(o[0xB1]&0x80)) {
            u16 h=*(u16 *)(o+0xB2);
            if(h&1) {
                u8 *q=&D_001BBE90[((s16)h>>1)+(D_001D545C<<10)];
                if(((*q>>4)&7)!=7) *q+=16;
            } else {
                u8 *q=&D_001BBE90[((s16)h>>1)+(D_001D545C<<10)];
                if((*q&7)!=7) *q+=1;
            }
            D_L01_00236B90.bytes[*(s16 *)(o+0xB2)]=o[0xB0]+2;
            if(o[0xB0]==255 || (!(*(u8 *)((s32)(u8)o[0xB0]+(s32)D_L01_001DFE80)&0x80) && (D_001BBC40[(u8)o[0xB0]+(D_001D545C<<4)]&0x80)))
                D_L01_00237800.x464[*(s16 *)(o+0xB2)]=o[0xB0]+2;
            }
            func_L01_004450F0((S_3A9AC0m *)o,5,-1);
            return;
        }
        if(!*(s32 *)(d+0xC54) && *(s32 *)(d+0xC5C) && !(o[0xB1]&0x80)) {
            u16 h=*(u16 *)(o+0xB2);
            if(h&1) {
                u8 *q=&D_001BBE90[((s16)h>>1)+(D_001D545C<<10)];
                if(((*q>>4)&7)!=7) *q+=16;
            } else {
                u8 *q=&D_001BBE90[((s16)h>>1)+(D_001D545C<<10)];
                if((*q&7)!=7) *q+=1;
            }
            D_L01_00236B90.bytes[*(s16 *)(o+0xB2)]=o[0xB0]+2;
            if(o[0xB0]==255 || (!(*(u8 *)((s32)(u8)o[0xB0]+(s32)D_L01_001DFE80)&0x80) && (D_001BBC40[(u8)o[0xB0]+(D_001D545C<<4)]&0x80)))
                D_L01_00237800.x464[*(s16 *)(o+0xB2)]=o[0xB0]+2;
        }
        *(s32 *)(d+0xD10)=*(s32 *)(d+0xC50);
        *(f32 *)(d+0xC6C)=*(f32 *)(d+0xC68);
    } else {
        *(s32 *)(d+0xD0C)=i;
        *(s32 *)(d+0xD10)=((D_003AB790 *)d)->path[i];
        *(f32 *)(d+0xC6C)=*(f32 *)(d+0xC64);
    }
    points=D_L01_0021F6C0[*(s32 *)(d+0xD10)];
    if(func_0038CF00(o+0x10,points+0x10)<D_L01_001DE3C4) {
        *(s32 *)(d+0xD14)=0;
        *(u128_t *)(d+0xD60)=*(u128_t *)(points+0x10);
        f=-1.0f;
    } else {
        *(f32 *)(d+0xD14)=-1.0f;
        *(u128_t *)(d+0xD60)=*(u128_t *)(o+0x10);
        f=func_0038CF00(o+0x10,points+0x10);
    }
    *(f32 *)(d+0xD6C)=f;
    if(end) {
        func_L01_004450F0((S_3A9AC0m *)o,5,-1);
        if(*(s32 *)(d+0xC54)) {
            f=func_0038CF00(points+0x10,points+(*(s32 *)points<<4));
            *(f32 *)(points+((*(s32 *)points-1)<<4)+0x1C)=f;
            *(u128_t *)(d+0xD70)=*(u128_t *)(points+0x10);
            *(f32 *)(d+0xD7C)=*(f32 *)(points+0x1C);
            *(u128_t *)(d+0xD80)=*(u128_t *)(points+0x20);
            *(f32 *)(d+0xD8C)=*(f32 *)(points+0x2C);
        } else {
            u8 *last=(u8 *)((*(s32 *)points<<4)+(s32)points);
            __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_003AB790 *)(last-16)),"m"(*(V_003AB790 *)last) : "vf1","vf2");
            func_0038CF68((u8 *)&tmp,&tmp,0.1f);
            *(f32 *)(points+((*(s32 *)points-1)<<4)+0x1C)=0.1f;
            last=(u8 *)((*(s32 *)points<<4)+(s32)points);
            __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%2\n\tsqc2 $vf1,%1\n\tlqc2 $vf1,%3\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(V_003AB790 *)(d+0xD70)),"=m"(tmp2) : "m"(tmp),"m"(*(V_003AB790 *)last) : "vf1","vf2");
            *(f32 *)(d+0xD7C)=0.1f;
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(V_003AB790 *)(d+0xD80)) : "m"(*(V_003AB790 *)(d+0xD70)),"m"(tmp2) : "vf1","vf2");
            *(f32 *)(d+0xD8C)=0.1f;
        }
    } else {
        func_L01_004450F0((S_3A9AC0m *)o,3,-1);
        item=D_L01_001E0100+(((D_003AB790 *)d)->ids[i]<<7);
        *(u128_t *)(d+0xD70)=*(u128_t *)(item+0x30);
        f=func_0038CF00(item+0x30,points+(*(s32 *)points<<4));
        *(f32 *)(points+((*(s32 *)points-1)<<4)+0x1C)=f;
        func_0038CF68(d+0xD80,(Vec4 *)item,10.0f);
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%0\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(*(V_003AB790 *)(d+0xD80)) : "m"(*(V_003AB790 *)(item+0x30)) : "vf1","vf2");
        *(f32 *)(d+0xD7C)=func_0038CF00(d+0xD80,item+0x30);
        *(f32 *)(d+0xD8C)=5.0f;
    }
}
