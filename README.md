# ZNC Priority Send Module

This network module will put every message/notice beginning
with *\(p!\)* in front of the ZNC's send queue.

It was created specifically for SteamDB's bot, as it can get
quite spammy and responses to user commands could get queued
for a while.

Use at your own risk, I provide absolutely no guarantees
that it won't crash or burn your server down.

Building:

1. `znc-dev` package installed to make `znc-buildmod` available
2. `CXXFLAGS="-std=c++11" znc-buildmod prioritysend.cpp`
