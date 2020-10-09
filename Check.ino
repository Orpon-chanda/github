void check() {
  data = 0;
  sum = 0;
  for (int i = 0; i < 7; i++) {
    s[i] = analogRead(5 - i);
    if (s[i] > th) s[i] = 1;
    else s[i] = 0;
    data += s[i] * binary[i];
    sum += s[i];    
  }
}
