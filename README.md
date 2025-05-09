# Simple database in C

My basic implementation of something like SQLite. Reads and writes to the `ccdb` file.
Comes with the following commands:

- `./ccadd [ID] [maker] [model] [year] [cpu] [memory] [description]` // Adds an item to the database
- `./ccdel [ID]` // Deleted an item from the database
- `./ccedit [ID]` // Edit a record, prompts user for info to fill in
- `./ccitem [id]` // Returns a record
- `./cclist` // Lists all records
- `./ccmatch [query]` // Finds all records with the provided substring
- `./ccyear [year 1] [year 2]` // Gets all records within the year range

`cctest.c` and a few of the other files contain some notes I took when learning this cool stuff!
