#include "common.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) RegionPoint;
typedef struct { int id; unsigned char links[4]; unsigned char edges[4]; int reserved; RegionPoint sphere; } RegionRecord;
typedef struct { int count; int reserved[3]; RegionPoint points[0]; } RegionGeometry;

LINKER_REMNANT("asm/levels", func_L19_0044A0B0);

/* localdecomp:start func_L19_0044A0C0 */
#include "vu0.h"

extern char *D_L19_0021D500[];
extern void func_0038CBA0(void *, int);
extern int func_L01_00477C80(int, int, int *, int *);
extern void func_0038CE20(void *, void *, float);
extern float func_0038CF38(void *, void *);

int func_L19_0044A0C0(void *unused, int *ids, RegionRecord *records, int capacity) {
    unsigned char depth[256];
    RegionPoint center;
    unsigned int visited;
    int pass = 1;
    int count = 0;
    int changed, edgeA, edgeB;
    int sourceEdge, targetEdge;
    RegionGeometry *geometry;
    float distance;
    func_0038CBA0(depth, 0x100);
    depth[0] = pass;
    visited = (unsigned int)depth;
    { int i, j;
    do {
        changed = 0;
        for (i = 0; i < capacity && count < capacity && ids[i] != -1; i++) {
            if (*(unsigned char *)(visited + i) == pass) {
                records[count++].id = ids[i];
                for (j = 0; j < capacity; j++) {
                    if (i == j || *(unsigned char *)(visited + j))
                        continue;
                    if (ids[j] == -1)
                        break;
                    if (func_L01_00477C80(ids[i], ids[j], &sourceEdge, &targetEdge)) {
                        changed = 1;
                        *(unsigned char *)(visited + j) = pass + 1;
                    }
                }
            }
        }
        pass++;
        if (!changed) break;
    } while (pass < 0x20);
    }
    { int i, j;
    for (i = 0; i < count; i++) {
        int none = 255;
        unsigned int base = (unsigned int)records->links;
        unsigned char *link;
        j = 3;
        link = (unsigned char *)(i * sizeof(RegionRecord) + base + j);
        for (; j >= 0; j--)
            *link-- = none;
    }
    }
    { int i, j, k;
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            int none = 255;
            if (func_L01_00477C80(records[i].id, records[j].id, &edgeA, &edgeB)) {
                ((RegionGeometry *)D_L19_0021D500[records[i].id])->points[edgeA].w = 0;
                ((RegionGeometry *)D_L19_0021D500[records[j].id])->points[edgeB].w = 0;
                for (k = 0; k < 4; k++) {
                    if (records[i].links[k] == none) {
                        records[i].links[k] = j;
                        records[i].edges[k] = edgeA;
                        break;
                    }
                }
                { int m = 0;
                int none = 255;
                unsigned char edge = edgeB;
                for (; m < 4; m++) {
                    if (records[j].links[m] == none) {
                        records[j].links[m] = i;
                        records[j].edges[m] = edge;
                        break;
                    }
                }}
            }
        }
    }
    }
    { int i, j, k;
    for (i = 0; i < count; i++) {
        geometry = (RegionGeometry *)D_L19_0021D500[records[i].id];
        qzero(&center);
        for (j = 0; j < geometry->count; j++)
            vec_add_ab(&center, &center, &geometry->points[j]);
        func_0038CE20(&center, &center, 1.0f / (float)geometry->count);
        center.w = 0;
        for (k = 0; k < geometry->count; k++) {
            distance = func_0038CF38(&center, &geometry->points[k]);
            if (distance > center.w)
                center.w = distance;
        }
        *(vu0_q *)&records[i].sphere = *(vu0_q *)&center;
    }
    }
    return count;
}
/* localdecomp:end func_L19_0044A0C0 */

/* localdecomp:start func_L19_0044A568 */
typedef struct RouteNode_0044A568 {
    /* 0x00 */ s32 path;
    /* 0x04 */ u8 neighbors[4];
    /* 0x08 */ u8 portals[4];
    /* 0x0C */ u16 flags;
    /* 0x0E */ u8 pad0E[0x12];
} RouteNode_0044A568;

extern char *D_L19_0021D500[];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L19_0044A9A0(f32 *, RouteNode_0044A568 *, s32, s32 *);
extern f32 func_L19_0044A860(char *, char *, f32 *, f32, f32);

s32 func_L19_0044A568(f32 *position, f32 *target, f32 *heading, RouteNode_0044A568 *nodes, s32 count, s32 *sourceNode, s32 *targetNode, f32 override, f32 margin) {
    u8 visited[256];
    s32 i, j, found, portal, step, routeDepth;
    s32 layer;
    char *path;
    f32 angle;
    *heading = func_0038D160(target[0] - position[0], target[1] - position[1]);
    if (override != 0.0f)
        *heading = func_0038DAB8(override, *heading);
    if (!func_L19_0044A9A0(position, nodes, count, sourceNode))
        return 0;
    if (!func_L19_0044A9A0(target, nodes, count, targetNode))
        return 0;
    if (nodes[*targetNode].flags & 1)
        return 0;
    if (*sourceNode == *targetNode)
        return 1;
    {
        s32 clear;
        for (clear = 0; clear < count; clear++)
            visited[clear] = 0;
    }
    found = -1;
    portal = -1;
    visited[*targetNode] = 1;
    for (layer = 1; layer < 50; layer++) {
        for (i = 0; i < count; i++) {
            if (visited[i] == layer) {
                for (j = 0; j < 4; j++) {
                    u32 neighbor = nodes[i].neighbors[j];
                    if (!(neighbor & 0x80) && !visited[neighbor] && (((u8)nodes[neighbor].flags ^ 1) & 1)) {
                        visited[neighbor] = layer + 1;
                        if (neighbor == *sourceNode) {
                            portal = nodes[i].portals[j];
                            found = i;
                        }
                    }
                }
            }
            if (found != -1)
                break;
        }
        if (found != -1)
            break;
    }
    if (found == -1)
        return 0;
    path = D_L19_0021D500[nodes[found].path];
    angle = *heading;
    routeDepth = visited[found];
    if (routeDepth >= 3) {
        s32 edge;
        step = routeDepth - 1;
        for (edge = 0; edge < 4; edge++) {
            if (visited[nodes[found].neighbors[edge]] == step) {
                s32 offset = nodes[found].portals[edge] * 16;
                angle = func_L19_0044A860(path + (offset + 0x10), path + (offset + 0x20), position, angle, margin);
                break;
            }
        }
    }
    *heading = func_L19_0044A860(path + (portal * 16 + 0x10), path + (portal * 16 + 0x20), position, angle, margin);
    return 1;
}
/* localdecomp:end func_L19_0044A568 */

/* localdecomp:start func_L19_0044A860 */
#include "vu0.h"
extern void func_0038CF68(float *, float *, float);
extern f32 func_0038DB00(f32, f32);

f32 func_L19_0044A860(char *a0, char *a1, f32 *position, f32 angle, f32 margin)
{
    float v0[4] __attribute__((aligned(16)));
    float v1[4] __attribute__((aligned(16)));
    float v2[4] __attribute__((aligned(16)));
    float half;
    float start;
    float mid;
    float f;

    vec_sub_ab(v0, a1, a0);
    func_0038CF68(v0, v0, margin);
    vec_add_ba(v1, a0, v0);
    vec_sub_ab(v2, a1, v0);

    start = func_0038D160(v1[0] - *(float *)position, v1[1] - *(float *)((char *)position + 4));
    half = func_0038DB00(func_0038D160(v2[0] - *(float *)position,
                                       v2[1] - *(float *)((char *)position + 4)), start) * 0.5f;
    mid = func_0038DAB8(half, start);
    angle = func_0038DB00(angle, mid);
    f = fabs_asm(half);
    if (f < angle)
        angle = f;
    if (angle < -f)
        angle = -f;
    return func_0038DAB8(angle, mid);
}
/* localdecomp:end func_L19_0044A860 */

/* localdecomp:start func_L19_0044A9A0 */
extern s32 func_L01_004463F8(f32 *p, f32 *v, s32 n);
extern f32 func_0038CF38(void *a, void *b);

/* from rac2-decomp's func_L02_0032EDD8 */
s32 func_L19_0044A9A0(f32 *point, RouteNode_0044A568 *nodes, s32 count, s32 *index) {
    s32 i;
    if (*index != -1) {
        char *entry;
        s32 n;
        entry = D_L19_0021D500[nodes[*index].path];
        n = *(s32 *)entry;
        entry += 0x10;
        if (func_L01_004463F8(point, (f32 *)entry, n) != 0)
            return 1;
    }
    for (i = 0; i < count; i++) {
        if (i != *index
            && func_0038CF38(point, (char *)&nodes[i] + 0x10) <= *(f32 *)((char *)&nodes[i] + 0x1C)) {
            char *entry;
            s32 n;
            entry = D_L19_0021D500[nodes[i].path];
            n = *(s32 *)entry;
            entry += 0x10;
            if (func_L01_004463F8(point, (f32 *)entry, n) != 0) {
                *index = i;
                return 1;
            }
        }
    }
    *index = -1;
    return 0;
}
/* localdecomp:end func_L19_0044A9A0 */

LINKER_REMNANT("asm/levels", func_L19_0044AAD8);
