# ZNC Priority Send Module

This network module will put every message/notice beginning
with *\(p!\)* in front of the ZNC's send queue.

It was created specifically for SteamDB's bot, as it can get
quite spammy and responses to user commands could get queued
for a while.