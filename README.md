# Bitcoin Transaction Parser (C++)

This is a beginner-friendly C++ command-line tool to parse raw Bitcoin transactions.

## Motivation
I built this project to understand the Bitcoin transaction format and improve my C++ skills while preparing for open-source contribution in the Bitcoin ecosystem.

## Features (Planned)
- Accept raw Bitcoin transaction hex as input
- Parse and display:
  - Version
  - Number of inputs
  - Number of outputs
  - Locktime

## Tech Stack
- C++
- Linux
- Git

## Status
🚧 Work in progress (actively developing)

## Learning Goals
- Understanding Bitcoin transaction structure
- Binary data parsing
- Writing clean C++ CLI programs
# Bitcoin Transaction Parser (C++)

A beginner-friendly C++ command-line tool that parses raw Bitcoin transaction
hex data and extracts basic transaction metadata.

This project is built as a stepping stone towards contributing to
Bitcoin Core and participating in **Summer of Bitcoin**.

---

## Features
- Accepts raw Bitcoin transaction hex input
- Calculates transaction hex length
- Extracts transaction version (little-endian)
- Simple and readable C++ implementation

---

## Build & Run

```bash
g++ src/main.cpp -o btc_parser
./btc_parser
