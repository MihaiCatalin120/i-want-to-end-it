#include "environment.h"

EnvItem level0Items[] = {{{0, 400, 800, 200}, true, GRAY},
                         {{200, 200, 400, 10}, true, GRAY},
                         {{100, 300, 100, 10}, true, GRAY},
                         {{600, 300, 100, 10}, true, GRAY}};

EnvItem level1Items[] = {
    {{0, 500, 800, 100}, true, GRAY},  {{0, 200, 50, 300}, true, GRAY},
    {{50, 300, 50, 200}, true, GRAY},  {{300, 300, 100, 10}, true, GRAY},
    {{500, 200, 100, 10}, true, GRAY}, {{500, 400, 100, 10}, true, GRAY},
};
const Level levels[] = {{
                            (Vector2){400.0f, 280.0f},
                            level0Items,
                            sizeof(level0Items) / sizeof(level0Items[0]),
                        },
                        {
                            (Vector2){10.0f, 280.0f},
                            level1Items,
                            sizeof(level1Items) / sizeof(level1Items[0]),
                        }};
