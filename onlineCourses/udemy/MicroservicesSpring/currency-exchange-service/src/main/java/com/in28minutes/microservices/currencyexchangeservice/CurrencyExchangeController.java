package com.in28minutes.microservices.currencyexchangeservice;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;
import com.in28minutes.microservices.currencyexchangeservice.ExchangeValue;

import java.math.BigDecimal;

@RestController
public class CurrencyExchangeController {

  @GetMapping("/currency-exchange/from/{from}/to/{to}")
  public ExchangeValue retrieveExchangeValue(@PathVariable String from, @PathVariable String to) {
    return new ExchangeValue(1000L, from, to, BigDecimal.valueOf(65));
  }
}
