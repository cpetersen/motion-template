#!/bin/sh
convert iTunesArtwork@2x.png -resize "1024x" iTunesArtwork.png
convert iTunesArtwork@2x.png -resize "57x" Icon.png
convert iTunesArtwork@2x.png -resize "72x" Icon-72.png
convert iTunesArtwork@2x.png -resize "114x" Icon@2x.png
convert iTunesArtwork@2x.png -resize "144x" Icon-72@2x.png
