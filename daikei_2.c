#include <stdio.h> 
 
 double dxf_1(double x) 
 { 
   return x*x*x*x - ​2​*x*x*x + x*x -​3​*x + ​1​;​//計算式を変更するところ 
 } 
  
  double trape_cal_y(double delta_x, int n){ 
     
     double y[​1000​]; 
     double sum, ans = ​0​; 
     double x = ​0​;​//範囲の初期値 
      
      for(int i = ​1​; i <= n; i++){ 
         
         y[i] = dxf_1(x); 
         x += delta_x; 
      } 
       
       sum = y[​1​] + y[n]; 
        
        for(int i = ​2​; i < n; i++){ 
          sum += ​2​ * y[i]; 
        } 
         
         ans = (delta_x / ​2​) * sum; 
          
          return ans; 
           
  } 
   
   double simpson_cal_y(double delta_x, int n){ 
      
      double y[​1000​]; 
      double sum, ans = ​0​; 
      double x = ​0​;​範囲の初期値 
       
        
         
            
            for(int i = ​1​; i <= n; i++){ 
               
               y[i] = dxf_1(x); 
               x += delta_x; 
            } 
             
             sum = y[​1​] + y[n]; 
              
              for(int i = ​2​; i < n; i+=​2​){ ​//×4 
                sum += ​4​ * y[i]; 
              } 
               
               for(int i = ​3​; i < n; i+=​2​){​//×2 
                 sum += ​2​ * y[i]; 
               } 
                
                 
                 ans = (delta_x / ​3​) * sum; 
                  
                  return ans; 
   } 
    
    int main(){ 
       
       int n; 
       double delta_x, trape_ans, simp_ans; 
        
        printf(​"台形公式をおこないます。範囲を何等分するか入力してください\n"​); 
        scanf(​"%d"​, ​&n); 
         
         delta_x = ​4​ / n;​//定積分の範囲を指定する(例.0~4 なら5) 
          
          trape_ans = trape_cal_y(delta_x, n); 
          simp_ans = simpson_cal_y(delta_x, n); 
           
           printf(​"台形法を使用した答えは...%lf\n"​,trape_ans); 
           printf(​"シンプソン法を使用した答えは...%lf\n"​, simp_ans);
