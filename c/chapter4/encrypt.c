void encrypt(char* message) {
  char c;
  while (*message) {
    *message = *message ^ 17;
    message++;
  }
}
