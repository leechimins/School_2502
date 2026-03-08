package ddwu.mobile.finalproject.network

import ddwu.mobile.finalproject.data.Quote
import retrofit2.http.GET
import retrofit2.http.Query

interface QuoteService {
    @GET("quotes/random")
    suspend fun getRandomQuote(
        @Query("tags") tags: String
    ): List<Quote>
}