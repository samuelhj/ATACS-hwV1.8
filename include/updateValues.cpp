
void updateBaseValue() // Við uppfærum gildi á kistu
{

    // Hreinsum þar sem gildin eru á skjánum.
    tft.fillRect(120,60,240,18,BLACK); // Hreinsum gildi fyrir þrýsting kistu
    // Við skrifum mælt gildi á kistunni
    float basePressure = 0.0;
    basePressure = readPressure();
    //pressure_ALL = basePressure; // þrýstingur úr öllum dekkjum
    tft.setTextSize(2);
    tft.setCursor(125,60);
    tft.println(basePressure);
    tft.setCursor(175,60);
    tft.println(" PSI");
    // Hreinsum þar sem gildin eru á skjánum.
    //tft.fillRect(130,140,60,48,BLACK); // Hreinsum gildi fyrir valinn þrýsting burt.
  
  if(debug == true)
  {
    tft.fillRect(140,140,60,120,BLACK); 
    tft.setTextSize(2); // Stillum textastærð á 2
    tft.setCursor(140,140); // Veljum staðsetningu
    tft.println(tiretoken);

   // tft.fillRect(20,220,240,18,BLACK); // Hreinsum gildi fyrir þrýsting kistu
    tft.setTextSize(2);
    tft.setCursor(20,220); // Veljum staðsetningu
    float pressure = pressure_LFT - selectedPressure_LFT;
    pressure = fabs(pressure);
    tft.println(pressure); // Skrifum út gildið.

    if(tiretoken == 0)
    {
      tft.setCursor(140,160); // Veljum staðsetningu
      float pressure = pressure_LRT - selectedPressure_LRT;
      pressure = fabs(pressure);
      tft.println(pressure); // Skrifum út gildið.
      tft.setCursor(140,180); 
      tft.println(interval_measure/1000);
      tft.setCursor(140,200); 
      tft.println(timer_measure/1000);
    }

    if(tiretoken == 1)
    {
      tft.setCursor(140,160); // Veljum staðsetningu
      float pressure = pressure_LRT - selectedPressure_LRT;
      pressure = fabs(pressure);
      tft.println(pressure); // Skrifum út gildið.
      tft.setCursor(140,180); 
      tft.println(interval_inflate_LRT/1000);
      tft.setCursor(140,200); 
      tft.println(interval_deflate_LRT/1000);
    }
    if(tiretoken == 2)
    {
      tft.setCursor(140,160); // Veljum staðsetningu
      float pressure = pressure_LFT - selectedPressure_LFT;
      pressure = fabs(pressure);
      tft.println(pressure); // Skrifum út gildið.
      tft.setCursor(140,180); 
      tft.println(interval_inflate_LFT/1000);
      tft.setCursor(140,200); 
      tft.println(interval_deflate_LFT/1000);
    }
    if(tiretoken == 3) 
    {
      tft.setCursor(140,160); // Veljum staðsetningu
      float pressure = pressure_RFT - selectedPressure_RFT;
      pressure = fabs(pressure);
      tft.println(pressure); // Skrifum út gildið.
      tft.setCursor(140,180); 
      tft.println(interval_inflate_RFT/1000);
      tft.setCursor(140,200); 
      tft.println(interval_deflate_RFT/1000);
    }
    if(tiretoken == 4)
    {
      tft.setCursor(140,160); // Veljum staðsetningu
      float pressure = pressure_RRT - selectedPressure_RRT;
      pressure = fabs(pressure);
      tft.println(pressure); // Skrifum út gildið.
      tft.setCursor(140,180);
      tft.println(interval_inflate_RRT/1000);
      tft.setCursor(140,200);
      tft.println(interval_deflate_RRT/1000);
    }
    if(tiretoken == 5)
    {
      tft.setCursor(140,160); // Veljum staðsetningu
      float pressure = pressure_ALL - selectedPressure;
      pressure = fabs(pressure);
      tft.println(pressure); // Skrifum út gildið.
      tft.setCursor(140,180);
      tft.println(interval_inflate/1000);
      tft.setCursor(140,200);
      tft.println(interval_deflate/1000);
    }
  }
} //updateBaseValue function closes

    void updateValues() // Við uppfærum gildi
{
    // Hreinsum þar sem gildin eru á skjánum.
    tft.setTextSize(2);
    tft.fillRect(20,170,60,50, BLACK); // Hreinsum gildið fyrir LRT
    tft.fillRect(20,20,60,50,BLACK); // Hreinsum gildið fyrir LFT
    tft.fillRect(240,20,60,50,BLACK); // Hreinsum gildið fyrir RFT
    tft.fillRect(240,170,60,50,BLACK); // Hreinsum gildið fyrir RRT

    // Skrifum mæld gildi.
    tft.setCursor(20,20); // Staðsetjum okkur v/m ofan
    if(selectedTire == 2)
    {
      tft.setTextColor(GREEN);
    }
    else
    {
      tft.setTextColor(WHITE);
    }
    tft.println(selectedPressure_LFT);
    tft.setCursor(20,40); // Erum fyrir neðan.
    tft.setTextColor(GREEN);
    tft.println(pressure_LFT); // Skrifum út gildi á staðsetningu

    tft.setCursor(240,20); // Staðsetjum okkur hægra megin að ofan
    if(selectedTire == 3)
    {
      tft.setTextColor(GREEN);
    }
    else
    {
      tft.setTextColor(WHITE);
    }
    tft.println(selectedPressure_RFT); // Valinn þrýstingur
    tft.setTextColor(GREEN);
    tft.setCursor(240,40); // Skrifum á RFT
    tft.println(pressure_RFT);


    tft.setCursor(20,170);
    if(selectedTire == 1)
    {
      tft.setTextColor(GREEN);
    }
    else
    {
      tft.setTextColor(WHITE);
    }
    tft.println(selectedPressure_LRT);
    tft.setTextColor(GREEN);
    tft.setCursor(20,190); // Skrifum á LRT
    tft.println(pressure_LRT);

    if(selectedTire == 4)
    {
      tft.setTextColor(GREEN);
    }
    else
    {
      tft.setTextColor(WHITE);
    }

    tft.setCursor(240,170);
    tft.println(selectedPressure_RRT);
    tft.setTextColor(GREEN);
    tft.setCursor(240,190); // Skrifum á RRT
    tft.println(pressure_RRT);

    // Skrifum menu textann
    tft.setTextColor(WHITE);
    tft.setTextSize(3); // Textastærð 3.
    tft.setCursor(130,20); // Setjum byrjunarreit
    tft.println("MENU"); // Skrifum Menu

    warningCheck(); //Athugum hvort viðvörun gildi á einhverju dekki

}
