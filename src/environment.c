#include "environment.h"

Platform level0Platforms[] = {{{0, 400, 800, 200}, true, GRAY},
                              {{200, 200, 400, 10}, true, GRAY},
                              {{100, 300, 100, 10}, true, GRAY},
                              {{600, 300, 100, 10}, true, GRAY}};

Spike level0Spikes[] = {
    {{400, 200}, {450, 200}, {425, 175}}, {{350, 200}, {400, 200}, {375, 175}},
    {{450, 400}, {500, 400}, {475, 375}}, {{400, 400}, {450, 400}, {425, 375}},
    {{350, 400}, {400, 400}, {375, 375}}, {{300, 400}, {350, 400}, {325, 375}},
};

Platform level1Platforms[] = {
    {{0, 500, 800, 100}, true, GRAY},  {{0, 200, 50, 300}, true, GRAY},
    {{50, 300, 50, 200}, true, GRAY},  {{300, 300, 100, 10}, true, GRAY},
    {{500, 200, 100, 10}, true, GRAY}, {{500, 400, 100, 10}, true, GRAY},
};
const Level levels[] = {
    {
        (Vector2){50.0f, 280.0f},
        level0Platforms,
        sizeof(level0Platforms) / sizeof(level0Platforms[0]),
        level0Spikes,
        sizeof(level0Spikes) / sizeof(level0Spikes[0]),
    },
    {
        (Vector2){10.0f, 200.0f},
        level1Platforms,
        sizeof(level1Platforms) / sizeof(level1Platforms[0]),
        {},
        0,
    }};
