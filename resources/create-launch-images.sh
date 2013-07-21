#!/bin/sh
convert original.png -resize "480x" -crop "320x480+80+0" Default.png
convert original.png -resize "960x" -crop "640x960+160+0" Default@2x.png
convert original.png -resize "1136x" -crop "640x1136+248+0" Default-568h@2x.png
convert original.png -resize "1004x" -crop "768x1004+118+0" Default~ipad.png
convert original.png -resize "1004x" -crop "768x1004+118+0" Default~ipad.png
convert original.png -resize "1024x" -crop "1024x748+0+138" Default-Landscape~ipad.png
convert original.png -resize "2008x" -crop "1536x2008+236+0" Default@2x~ipad.png
convert original.png -resize "2048x" -crop "2048x1496+0+276" Default-Landscape@2x~ipad.png
