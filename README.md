Redis-Inspired In-Memory Database | C++17, TCP/IP, Multithreading, POSIX Sockets

Engineered a Redis-inspired in-memory database in C++17, implementing SET, GET, DEL, EXISTS, SIZE, Lists, Hashes, and TTL expiration using modular OOP, Command/Factory patterns, and Dependency Injection.

Built a TCP client-server architecture using POSIX sockets (socket, bind, listen, accept, recv, send) with a thread-per-client concurrency model, enabling simultaneous client connections and shared database access.

Implemented thread-safe concurrent storage using std::mutex and RAII-based std::lock_guard, alongside a background expiration worker and O(1) LRU eviction using unordered_map + doubly linked std::list to manage bounded in-memory state.

Designed durable command-based persistence with Append-Only File (AOF) replay, persisting state-changing operations across KV, Lists, Hashes, and TTLs using absolute expiration timestamps, enabling database recovery after server restart.
