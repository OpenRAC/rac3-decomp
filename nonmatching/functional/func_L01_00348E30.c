/* functional: high. Near miss (312 words): scheduling/address arithmetic only; all calls, offsets, constants verified. */
/* localdecomp:start func_L01_00348E30 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_00348E30;
typedef struct { Vec_00348E30 point[3]; Vec_00348E30 a, b; s16 active, life; f32 uv, uv2, fade; } Trail_00348E30;
typedef struct { Vec_00348E30 point[4]; s32 color[4]; f32 uv[4][2]; u8 rest[32]; } Packet_00348E30;
__asm__(".extern D_L01_001DD350, 4");
__asm__(".extern D_L01_001DD354, 4");
__asm__(".extern D_L01_001DD358, 4");
__asm__(".extern D_L01_001DD360, 4");
__asm__(".extern D_L01_001DD364, 4");
__asm__(".extern D_L01_001DD368, 4");
__asm__(".extern D_L01_001DD374, 4");
__asm__(".extern D_L01_001DD378, 4");
__asm__(".extern D_L01_001DD37C, 4");
__asm__(".extern D_L01_001DD380, 4");
__asm__(".extern D_L01_001DD384, 4");
__asm__(".extern D_L01_001DD388, 4");
__asm__(".extern D_L01_001DD38C, 4");
__asm__(".extern D_L01_001DD390, 4");
extern f32 D_L01_001DD350, D_L01_001DD354, D_L01_001DD358;
extern s32 D_L01_001DD360, D_L01_001DD364, D_L01_001DD368;
extern f32 D_L01_001DD374;
extern s32 D_L01_001DD378, D_L01_001DD37C, D_L01_001DD380;
extern f32 D_L01_001DD384;
extern s32 D_L01_001DD388, D_L01_001DD38C, D_L01_001DD390;
extern Vec_00348E30 D_L01_002B2970[];
extern Vec_00348E30 D_L01_001E29C0;
void func_L01_00348E30(Moby *moby) {
    extern char *func_L01_00457480(s32, s32);
    extern Info *func_L01_004574B0(s32, s32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    Packet_00348E30 packet;
    Vec_00348E30 a, normal, b, center;
    Vec_00348E30 rings[3][20];
    Vec_00348E30 temp, width;
    Vars *vars=moby->vars;
    s32 i=0;
    Trail_00348E30 *trails;
    s32 next;
    trails=(Trail_00348E30 *)(func_L01_00457480(0xC04,vars->unk1A)+func_L01_004574B0(0xC04,vars->unk1A)->unk0);
    func_003D93B0(&packet,0x15,0,0x80);
    do {
        next=i+1;
        if(trails[i].active) {
            s32 j,k;
            s32 color;
            s32 faded;
            f32 fade;
            f32 u,v;
            Vec_00348E30 *row;
            a=trails[i].a;
            b=trails[i].b;
            func_0038CE90(&normal,&a,&b);
            fade=trails[i].life*trails[i].fade;
            color=D_L01_001DD360;
            faded=((s32)(fade*(f32)D_L01_001DD368)<<24)|color;
            packet.color[3]=faded;packet.color[2]=faded;packet.color[1]=faded;packet.color[0]=faded;
            for(j=0;j<3;j++) {
                Vec_00348E30 *out=rings[j];
                Vec_00348E30 *circle=D_L01_002B2970;
                center=trails[i].point[j];
                for(k=19;k>=0;k--) {
                    func_0038CE20(temp.v,circle->v,D_L01_001DD358);
                    circle++;
                    func_0038D028(out,&temp,&a);
                    out++;
                }
            }
            color=D_L01_001DD364;
            u=trails[i].uv;
            for(row=rings[1];row<rings[2]+20;row+=20) {
                v=0;
                for(k=0;k<20;k++) {
                    s32 n=(k+1)%20;
                    packet.point[0]=row[k];
                    packet.point[1]=row[n];
                    packet.point[2]=row[k-20];
                    packet.point[3]=row[n-20];
                    packet.color[2]=color;packet.color[3]=color;
                    packet.uv[0][0]=u;packet.uv[0][1]=v;
                    packet.uv[1][0]=u;packet.uv[1][1]=v+D_L01_001DD354;
                    packet.uv[2][0]=u+D_L01_001DD350;packet.uv[2][1]=v;
                    packet.uv[3][0]=u+D_L01_001DD350;packet.uv[3][1]=v+D_L01_001DD354;
                    v+=D_L01_001DD354;
                    func_003D2DA0(&packet,0,0);
                }
                color=faded;
            }
            func_003D93B0(&packet,14,1,0x80);
            faded=((s32)(fade*(f32)D_L01_001DD380)<<24)|D_L01_001DD37C;
            packet.color[3]=faded;packet.color[2]=faded;packet.color[1]=faded;packet.color[0]=faded;
            packet.uv[0][0]=0;packet.uv[0][1]=0;
            packet.uv[1][0]=0;packet.uv[1][1]=1;
            packet.uv[2][0]=0.5f;packet.uv[2][1]=0;
            packet.uv[3][0]=0.5f;packet.uv[3][1]=1;
            __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(*(&temp)) : "m"(*(&D_L01_001E29C0)), "m"(*(&trails[i].point[0])) : "vf1", "vf2");
            color=D_L01_001DD378;
            func_0038CE90(&normal,&a,&temp);
            func_0038CF68(&width,&normal,D_L01_001DD374);
            for(j=1;j<3;j++) {
                __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(*(&packet.point[0])) : "m"(*(&trails[i].point[j])), "m"(*(&width)) : "vf1", "vf2");
                __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(*(&packet.point[1])) : "m"(*(&trails[i].point[j])), "m"(*(&width)) : "vf1", "vf2");
                __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(*(&packet.point[2])) : "m"(*(&trails[i].point[j-1])), "m"(*(&width)) : "vf1", "vf2");
                __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(*(&packet.point[3])) : "m"(*(&trails[i].point[j-1])), "m"(*(&width)) : "vf1", "vf2");
                packet.color[3]=color;packet.color[2]=color;
                func_003D2DA0(&packet,0,0);
                color=faded;
                packet.uv[0][0]=packet.uv[2][0];packet.uv[1][0]=packet.uv[2][0];
                packet.uv[2][0]=3;packet.uv[3][0]=3;
            }
            func_003D93B0(&packet,23,1,0x80);
            faded=((s32)(fade*(f32)D_L01_001DD390)<<24)|D_L01_001DD38C;
            packet.color[3]=faded;packet.color[2]=faded;packet.color[1]=faded;packet.color[0]=faded;
            packet.uv[0][0]=0;packet.uv[0][1]=0;
            packet.uv[1][0]=0;packet.uv[1][1]=1;
            packet.uv[2][0]=1;packet.uv[2][1]=0;
            packet.uv[3][0]=1;packet.uv[3][1]=1;
            u=trails[i].uv2;
            packet.uv[2][0]=u+0.5f;packet.uv[3][0]=u+0.5f;
            color=D_L01_001DD388;
            func_0038CF68(&width,&normal,D_L01_001DD384);
            for(j=1;j<3;j++) {
                __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(*(&packet.point[0])) : "m"(*(&trails[i].point[j])), "m"(*(&width)) : "vf1", "vf2");
                __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(*(&packet.point[1])) : "m"(*(&trails[i].point[j])), "m"(*(&width)) : "vf1", "vf2");
                __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(*(&packet.point[2])) : "m"(*(&trails[i].point[j-1])), "m"(*(&width)) : "vf1", "vf2");
                __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(*(&packet.point[3])) : "m"(*(&trails[i].point[j-1])), "m"(*(&width)) : "vf1", "vf2");
                packet.color[3]=color;packet.color[2]=color;
                func_003D2DA0(&packet,0,0);
                color=faded;
                packet.uv[0][0]=packet.uv[2][0];packet.uv[1][0]=packet.uv[2][0];
                packet.uv[2][0]=u+3;packet.uv[3][0]=u+3;
            }
        }
        i=next;
    }while(i<3);
}
/* localdecomp:end func_L01_00348E30 */
