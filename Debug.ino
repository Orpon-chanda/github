void debug() {
  for (int i = 6; i >= 0; i--) {
    Serial.print(s[i]);
    Serial.print(" ");
  }
  Serial.print(" ");
  Serial.print(sum);
  Serial.print(" ");
  Serial.print(data);
  Serial.print(" ");
  sonarf = sonar.ping_cm();
  Serial.println(sonarf);
}
