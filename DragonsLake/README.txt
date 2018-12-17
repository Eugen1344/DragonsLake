Hello!

Your task is to implement *simple* crimsonland-like game
(please, see Crimsonland 2003 game for a reference)

You should be able to move your avatar with left/right/up/down butttons +
Have a reticle following mouse button +
Enemies should be spawned randomly on a map and run to the player by a shortest path. Enemies should not be spawned too close to the player +
Enemies should have random similar speed +
Enemies should not pass through each other +
Once enemy touches player, player dies and game restarts +

Player can shoot (e.g. by presing left mouse button). +
Once it is pressed, a bullet should move at the given direction. +
If bullet is intersected with an enemy it should die, bullet also disappears. +
If there is no ammo, then oldest bullet should disappear and new one should be spawned. +

Player should always be in the center of a screen (i.e. if it moves map is recentered). You can add extra threshold, but it is not necessary +

Window size, map size, number of bullets and enemis should be arbitrary and it should be possible to set it from the command-line, e.g.:

> game.exe -window 800x600 -map 1000x1000 -num_enemies 10 -num_ammo 3

Size of map is in pixels (same as sprite size)

Functionality provided by Framework should be enough to do all required drawing.
You can load TGA, JPG and PNG images as sprites.
Please, see game.cpp for a template implementation.
When implementing application take special care about performance and memeory usage.
Try to use data oriented programming approach.

Good luck!
Bye.

--


