# Level system

The level system is a system that allows you to create levels for your game.

## How to create a level
Create a json file with your level name in the levels folder. The level name is the name of the file without the extension. For example, if you create a file named `level1.json`, the level name is `level1`.
You should have the following structure:
```
{
  "moving_camera": BOOL,
  "level":
           ["wwwwwwwwwwww",
            "whhhhhhhhhhw",
            "whhhhhhhhhhw",
            "whhhhhhhhhhw",
            "whhhhhhhhhhw",
            "whhhhhhhhhhw",
             whhhhhhhhhhw",
            "whhhhhhhhhhw",
            "whhhhhhhhhhw",
            "whhhhhhhhhhw",
            "whhhhhhhhhhw",
            "wwwwwwwwwwww"]
}
```

every character in the level string represents a tile. The following characters are valid: `w`, `h`, `s`, `t`, `p`
* `w` is a wall tile
* `h` is a hole tile
* `s` is a saw tile, this is a deadly object
* `t` is a teleporter tile, if you use one, there must be two in the level. one teleporter won't do anything, more will not work.
* `p` is a player spawn tile, there can only be one in the level

If you set `moving_camera` to true, the camera will gradually move up. If the player gets below this, he will die.