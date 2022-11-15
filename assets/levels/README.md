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

evey character in the level string represents a tile. The following characters are valid: `w`, `h`
`w` is a wall tile
`h` is a hole tile
